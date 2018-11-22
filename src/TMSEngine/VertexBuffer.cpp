#include "VertexBuffer.h"

#include <iostream>

using namespace tmsengine;


VertexBuffer::VertexBuffer() : components(0), dirty(false)
{
	//Create a new VBO on the GPU and bind it
	glGenBuffers(1, &vboID);

	if (!vboID)
	{
		throw std::exception();
	}
}

void VertexBuffer::add(glm::vec2 value)
{
	if (!components)
	{
		components = 2;
	}

	if (components != 2)
	{
		throw std::exception();
	}

	data.push_back(value.x);
	data.push_back(value.y);
	dirty = true;
}

void VertexBuffer::add(glm::vec3 value)
{

	if (!components)
	{
		components = 3;
	}

	if (components != 3)
	{
		throw std::exception();
	}

	data.push_back(value.x);
	data.push_back(value.y);
	data.push_back(value.z);
	dirty = true;
}

void VertexBuffer::add(glm::vec4 value)
{
	if (!components)
	{
		components = 4;
	}

	if (components != 4)
	{
		throw std::exception();
	}

	data.push_back(value.x);
	data.push_back(value.y);
	data.push_back(value.z);
	data.push_back(value.w);
	dirty = true;
}

int VertexBuffer::getComponents()
{
	if (!components)
	{
		throw std::exception();
	}

	return components;
}

int VertexBuffer::getDataSize()
{
	return data.size();
}

GLuint VertexBuffer::getID()
{
	if (dirty)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vboID);

		//Upload a copy of the data from memory into the new VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data.at(0), GL_STATIC_DRAW);

		//Reset the state
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		dirty = false;
	}

	return vboID;
}

