#ifndef TMSENGINE_TEXTURE_H_
#define TMSENGINE_TEXTURE_H_

#include <gl/glew.h>
#include <glm/glm.hpp>
#include <string>

namespace tmsengine
{
class Texture
{
public:
	Texture(std::string path);
	~Texture();
	
	//void setPixel(unsigned int x, unsigned int y, glm::vec3 color);
	//void setPixel(unsigned int x, unsigned int y, glm::vec4 color);
	
	GLuint getID();

	glm::vec2 getSize();
private:
	GLuint ID;

	bool dirty;
	int type;
	
	std::shared_ptr<Texture> create(unsigned int width, unsigned int height);
	std::shared_ptr<Texture> load(std::string path);

	glm::vec2 size;
};
}
#endif