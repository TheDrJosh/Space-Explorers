#include "Renderer.h"

Renderer::Renderer()
{
	
}

void Renderer::drawSprite(glm::vec3 position, float roation, glm::vec2 scale, glm::vec4 tint, Texture texture, bool flipX, bool flipY)
{
	Quad quad(position, roation, scale, tint, texture.gpuTexture(), flipX, flipY);

	batchRenderer.AddQuad(quad);
}
