#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>
#include <gl/glew.h>

Texture::Texture(std::string path)
{
	int channels;
	imageData = std::shared_ptr<uint8_t[]>(stbi_load(path.c_str(), &width, &height, &channels, 4));
	if (imageData == NULL) {
		std::cout << "Error in loading the image" << std::endl;;
		exit(1);
	}

#ifdef _DEBUG
	std::cout << "Loaded image with a width of " << width << "px, a height of " << height << "px and " << channels << " channels" << std::endl;
#endif
}

Texture::Texture(int width, int height, glm::u8vec4 fillColor)
{
	imageData = std::make_shared<uint8_t[]>(width * height * 4);
	this->width = width;
	this->height = height;

	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			imageData[(i + j * width) * 4 + 0] = fillColor.r;
			imageData[(i + j * width) * 4 + 1] = fillColor.g;
			imageData[(i + j * width) * 4 + 2] = fillColor.b;
			imageData[(i + j * width) * 4 + 3] = fillColor.a;
		}
	}


}

void Texture::set(size_t x, size_t y, glm::u8vec4 color)
{
	imageData[(x + y * width) * 4 + 0] = color.r;
	imageData[(x + y * width) * 4 + 1] = color.g;
	imageData[(x + y * width) * 4 + 2] = color.b;
	imageData[(x + y * width) * 4 + 3] = color.a;
}

glm::u8vec4 Texture::get(size_t x, size_t y)
{
	return glm::vec4(
		imageData[(x + y * width) * 4 + 0],
		imageData[(x + y * width) * 4 + 1],
		imageData[(x + y * width) * 4 + 2],
		imageData[(x + y * width) * 4 + 3]);
}

int Texture::getWidth()
{
	return width;
}

int Texture::getHeight()
{
	return height;
}

glm::ivec2 Texture::getSize()
{
	return glm::ivec2(width, height);
}

std::weak_ptr<uint8_t[]> Texture::getPointer()
{
	return std::weak_ptr<uint8_t[]>(imageData);
}

void Texture::gpuReupload()
{
	if (!*gpuActivePtr)
		exit(1);
	

	glBindTexture(GL_TEXTURE_2D, *gpuTexturePtr);
	glTextureSubImage2D(*gpuTexturePtr, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, &imageData);
	//glGenerateMipmap(GL_TEXTURE_2D);
}

uint32_t Texture::gpuTexture()
{
	if (!*gpuActivePtr)
	{

		glGenTextures(1, &*gpuTexturePtr);
		glBindTexture(GL_TEXTURE_2D, *gpuTexturePtr);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.get());
		//glGenerateMipmap(GL_TEXTURE_2D);

		*gpuActivePtr = true;


	}
	return *gpuTexturePtr;
}
