#ifndef TMSENGINE_SHADERPROGRAM_H_
#define TMSENGINE_SHADERPROGRAM_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace tmsengine
{

	class VertexArray;
	class Texture;

	struct Sampler
	{
		GLuint samplerID;
		std::shared_ptr<Texture> texture;
	};

	class ShaderProgram
	{
	public:
		ShaderProgram(std::string vert, std::string frag);

		void draw(std::shared_ptr<VertexArray> vertexArray);
		void setUniform(std::string uniform, glm::vec4 value);
		void setUniform(std::string uniform, float value);
		void setUniform(std::string uniform, glm::mat4 value);
		void setUniform(std::string uniform, std::shared_ptr<Texture> texture);

		GLuint getID();
	private:
		GLuint programID;
		std::vector<Sampler> samplers;
	};

}
#endif