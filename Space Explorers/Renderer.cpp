#include "Renderer.h"
#include <gl/glew.h>
#include <iostream>

Renderer::Renderer()
{
#ifdef _DEBUG
	int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
	if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
	{
		std::cout << "Opengl Debug Enabled!" << std::endl;
	}
	else
	{
		std::cout << "Opengl Debug Failed To Enabled!" << std::endl;
	}
#endif // DEBUG
}

void Renderer::drawSprite(glm::vec3 position, float roation, glm::vec2 scale, glm::vec4 tint, Texture texture, bool flipX, bool flipY)
{
	Quad quad(position, roation, scale, tint, texture.gpuTexture(), flipX, flipY);

	batchRenderer.AddQuad(quad);
}
