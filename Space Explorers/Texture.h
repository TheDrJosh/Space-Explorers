#pragma once
#include <string>
#include <glm/glm.hpp>
#include <memory>
#include <array>
class Texture
{
public:
	Texture(std::string path);
	Texture(int width, int height, glm::u8vec4 fillColor);
	void set(int x, int y, glm::u8vec4 color);
	glm::u8vec4 get(int x, int y);
	int getWidth();
	int getHeight();
	glm::ivec2 getSize();
	std::weak_ptr<uint8_t[]> getPointer();

private:
	int width, height;
	std::shared_ptr<uint8_t[]> img;
};

