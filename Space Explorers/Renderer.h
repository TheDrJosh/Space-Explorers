#pragma once
#include <glm/glm.hpp>
#include"Texture.h"
#include "BatchRenderer.h"

class Renderer
{
public:
	Renderer();
	void drawSprite(glm::vec3 position, float roation, glm::vec2 scale, glm::vec4 tint, Texture texture, bool flipX, bool flipY);
	//void render

private:
	BatchRenderer batchRenderer;
};

