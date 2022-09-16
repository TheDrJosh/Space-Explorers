#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glew.h>
#include <iostream>

ExplorerEngine::Render::Texture::Texture()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	uint8_t data[4] = {
		255,255,255,255
	};

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

}

ExplorerEngine::Render::Texture::Texture(std::string path)
{
	name = path;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int nrChannels;
	uint8_t* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
		int format;

		switch (nrChannels)
		{
		case 1:
			format = GL_R;
			break;
		case 2:
			format = GL_RG;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		default:
			format = GL_RGB;
			break;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}
void ExplorerEngine::Render::Texture::use(int textureUnit)
{
	if (textureUnit >= 0 && textureUnit < 32)
	{
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
}
std::string ExplorerEngine::Render::Texture::getName()
{
	return name;
}
