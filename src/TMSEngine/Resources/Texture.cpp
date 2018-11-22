#include "Texture.h"

#include <stb_image/stb_image.h>

namespace tmsengine
{
	Texture::Texture(std::string path)
	{
		int weight = 0;
		int height = 0;
		int channels = 0;
		unsigned char *data = stbi_load(path.c_str(), &weight, &height, &channels, 4);

		if (!data)
		{
			throw std::exception();
		}

		size.x = weight;
		size.y = height;

		glGenTextures(1, &ID);

		if (!ID)
		{
			throw std::exception();
		}

		glBindTexture(GL_TEXTURE_2D, ID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, weight, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		free(data);
	
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture()
	{
		
	}

	glm::vec2 Texture::getSize()
	{
		return size;
	}

	GLuint Texture::getID()
	{
		return ID;
	}

}