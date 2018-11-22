#include "ShaderProgram.h"
#include "VertexArray.h"
#include "Resources/Texture.h"

#include <glm/ext.hpp>

#include <fstream>
#include <iostream>

using namespace tmsengine;


ShaderProgram::ShaderProgram(std::string vert, std::string frag)
{
	std::ifstream file(vert.c_str());
	std::string vertexSource;

	if (!file.is_open())
	{
		throw std::exception();
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		vertexSource += line + "\n";
	}

	file.close();
	file.open(frag.c_str());
	std::string fragSource;

	if (!file.is_open())
	{
		throw std::exception();
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		fragSource += line + "\n";
	}

	//Sets up the vertex shader
	const GLchar *vertexShaderSource = vertexSource.c_str();

	//Create new shader, attach shader source code, compile the code and check for errors
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderID);
	GLint success = 0;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

	char log[512];

	if (!success)
	{
		glGetShaderInfoLog(vertexShaderID, 512, NULL, log);
		std::cout << "Vertex shader failed to compile: " << log << "\nPress any key to continue...\n";
		std::getchar();

		throw std::exception();

	}


	//Sets up the fragment shader
	const GLchar *fragmentShaderSource = fragSource.c_str();

	//Create a new fragment shader, attach fragment source code, compile the code and check for errors
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShaderID);
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderID, 512, NULL, log);
		std::cout << "Fragment shader failed to compile: " << log << "\nPress any key to continue...\n";
		std::getchar();
		throw std::exception();
	}

	programID = glCreateProgram();
	//Create a new shader program to attach the shader objects
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

	//Ensure the VAO "position" attribute stream is the same as the first position during the link.
	glBindAttribLocation(programID, 0, "in_Position");
	//Ensure the VAO "color" attribute stream is the same as the original during the link.
	glBindAttribLocation(programID, 1, "in_Color");
	//Ensure the VAO "texcoord" attribute stream is the same during link.
	glBindAttribLocation(programID, 2, "in_TexCoord");
	//Ensure the VAO "normal" attribute stream is the same during link.
	glBindAttribLocation(programID, 3, "in_Normal");

	if (glGetError() != GL_NO_ERROR)
	{
		throw std::exception();
	}

	//Perform the link and check for failure
	glLinkProgram(programID);
	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	//Detach and destroy the shader objects
	glDetachShader(programID, vertexShaderID);
	glDeleteShader(vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(fragmentShaderID);
}

void ShaderProgram::draw(std::shared_ptr<VertexArray> vertexArray)
{
	//Tell OpenGL to use the shader program and the VAO
	glUseProgram(programID);
	glBindVertexArray(vertexArray->getID());

	for (size_t i = 0; i < samplers.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		if (samplers.at(i).texture)
		{
			glBindTexture(GL_TEXTURE_2D, samplers.at(i).texture->getID());
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	//Draw three vertices
	glDrawArrays(GL_TRIANGLES, 0, vertexArray->getVertexCount());

	for (size_t i = 0; i < samplers.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	//Reset the state
	glBindVertexArray(0);
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, glm::vec4 value)
{
	GLint uniformID = glGetUniformLocation(programID, uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(programID);
	glUniform4f(uniformID, value.x, value.y, value.z, value.w);
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, float value)
{
	GLint uniformID = glGetUniformLocation(programID, uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(programID);
	glUniform1f(uniformID, value);
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, glm::mat4 value)
{
	GLint uniformID = glGetUniformLocation(programID, uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(programID);
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(value));
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, std::shared_ptr<Texture> texture)
{
	GLint uniformID = glGetUniformLocation(programID, uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	for (size_t i = 0; i < samplers.size(); i++)
	{
		if (samplers.at(i).samplerID == uniformID)
		{
			samplers.at(i).texture = texture;

			glUseProgram(programID);
			glUniform1i(uniformID, i);
			glUseProgram(0);
			return;
		}
	}

	Sampler s;
	s.samplerID = uniformID;
	s.texture = texture;
	samplers.push_back(s);

	glUseProgram(programID);
	glUniform1i(uniformID, samplers.size() - 1);
	glUseProgram(0);
}

GLuint ShaderProgram::getID()
{
	return programID;
}