#pragma once
#include <glm/glm.hpp>
#include"Texture.h"

using GPUTexture = uint32_t;

class Renderer
{
public:
	Renderer();
	GPUTexture addTexture(Texture texture);
	void drawSprite(glm::vec3 position, float roation, glm::vec2 scale, glm::vec4 tint, GPUTexture texture);
};

