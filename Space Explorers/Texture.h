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
	void set(size_t x, size_t y, glm::u8vec4 color);
	glm::u8vec4 get(size_t x, size_t y);
	int getWidth();
	int getHeight();
	glm::ivec2 getSize();
	std::weak_ptr<uint8_t[]> getPointer();
	void gpuReupload();
	uint32_t gpuTexture();

private:
	int width, height;
	std::shared_ptr<uint8_t[]> imageData;
	std::shared_ptr<uint32_t> gpuTexturePtr = std::make_shared<uint32_t>(0);
	std::shared_ptr<bool> gpuActivePtr= std::make_shared<bool>(false);
};

