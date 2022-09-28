#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

Texture::Texture(std::string path)
{
	int channels;
	img = std::make_shared<uint8_t[]>(stbi_load(path.c_str(), &width, &height, &channels, 4));
	if (img == NULL) {
		std::cout << "Error in loading the image" << std::endl;;
		exit(1);
	}

#ifdef DEBUG
	std::cout << "Loaded image with a width of " << width << "px, a height of " << height << "px and " << channels << " channels" << std::endl;
#endif
}

Texture::Texture(int width, int height, glm::u8vec4 fillColor)
{
	img = std::make_shared<uint8_t[]>(new uint8_t[width * height * 4]);
	this->width = width;
	this->height = height;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			img[(i + j * width) * 4 + 0] = fillColor.r;
			img[(i + j * width) * 4 + 1] = fillColor.g;
			img[(i + j * width) * 4 + 2] = fillColor.b;
			img[(i + j * width) * 4 + 3] = fillColor.a;
		}
	}

}

void Texture::set(int x, int y, glm::u8vec4 color)
{
	img[(x + y * width) * 4 + 0] = color.r;
	img[(x + y * width) * 4 + 1] = color.g;
	img[(x + y * width) * 4 + 2] = color.b;
	img[(x + y * width) * 4 + 3] = color.a;
}

glm::u8vec4 Texture::get(int x, int y)
{
	return glm::vec4(
		img[(x + y * width) * 4 + 0],
		img[(x + y * width) * 4 + 1],
		img[(x + y * width) * 4 + 2],
		img[(x + y * width) * 4 + 3]);
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
	return std::weak_ptr<uint8_t[]>(img);
}
