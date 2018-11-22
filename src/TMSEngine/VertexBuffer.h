#ifndef TMSENGINE_VERTEXBUFFER_H_
#define TMSENGINE_VERTEXBUFFER_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace tmsengine
{

class VertexBuffer
{
public:
	VertexBuffer();

	void add(glm::vec2 value);
	void add(glm::vec3 value);
	void add(glm::vec4 value);

	int getComponents();
	int getDataSize();

	GLuint getID();
private:
	GLuint vboID;

	int components;
	bool dirty;
	
	std::vector<GLfloat> data;
};
}
#endif