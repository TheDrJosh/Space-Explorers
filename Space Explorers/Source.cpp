#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <glm/ext/scalar_constants.hpp>

#include "Space Engine/Window.h"
#include "Space Engine/SpriteRenderer.h"

int main()
{
	SpaceEngine::Window window(1920, 1080, "Space Explorer");

	SpaceEngine::Renderer::SpriteRenderer spriteRenderer(&window);

	SpaceEngine::Renderer::Quad quad;
	quad.rotation = glm::pi<float>() / 4;
	quad.scale = glm::vec2(2, 1);
	quad.position = glm::vec2(1, 0);
	quad.color = glm::vec4(1, 0, 1, 1);

	SpaceEngine::Renderer::Quad quad2;
	//quad2.rotation = 0.2;
	quad2.scale = glm::vec2(2, 1);
	//quad2.position = glm::vec2(1, 0);
	quad2.color = glm::vec4(1, 1, 0, 1);

	//quad.print();

	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		spriteRenderer.AddQuad(quad);
		spriteRenderer.AddQuad(quad2);

		spriteRenderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

