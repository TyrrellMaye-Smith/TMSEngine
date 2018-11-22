#ifndef TMSENGINE_VERTEXARRAY_H_
#define TMSENGINE_VERTEXARRAY_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

namespace tmsengine
{

class VertexBuffer;

class VertexArray
{
public:
	VertexArray();
	VertexArray(std::string path);

	void setBuffer(std::string attribute, std::shared_ptr<VertexBuffer> buffer);
	int getVertexCount();

	GLuint getID();
private:
	GLuint vaoID;

	std::vector<std::shared_ptr<VertexBuffer>> buffers;

	void splitStringWhiteSpace(std::string& input, std::vector<std::string>& output);
	void splitString(std::string& input, char splitter, std::vector<std::string>& output);

	bool dirty;
};
}
#endif