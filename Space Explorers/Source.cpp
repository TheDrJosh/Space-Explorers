#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <glm/ext/scalar_constants.hpp>

#include "Space Engine/Window.h"
#include "Space Engine/SpriteRenderer.h"
#include "Space Engine/Texture.h"


int main()
{
	SpaceEngine::Window window(1920, 1080, "Space Explorer");

	SpaceEngine::Renderer::SpriteRenderer spriteRenderer(&window);
	
	SpaceEngine::Renderer::Texture texture("D:/Dev/cpp Games/Space Explorers/Space Explorers/container.jpg");

	SpaceEngine::Renderer::Quad quad;
	quad.rotation = glm::pi<float>() / 4;
	quad.scale = glm::vec2(2, 1);
	quad.position = glm::vec2(1, -1);
	quad.color = glm::vec4(1, 0, 1, 1);
	quad.depth = -1;

	SpaceEngine::Renderer::Quad quad2;
	quad2.position = glm::vec2(0, -1);
	quad2.scale = glm::vec2(2, 1);
	quad2.color = glm::vec4(1, 1, 0, 1);

	SpaceEngine::Renderer::Quad quad3;
	quad3.position = glm::vec2(0, 1);
	quad3.scale = glm::vec2(2, 2);
	quad3.texture = texture;

	quad.print();
	std::cout << std::endl;
	quad2.print();
	std::cout << std::endl;
	quad3.print();

	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		spriteRenderer.AddQuad(quad);
		spriteRenderer.AddQuad(quad2);
		spriteRenderer.AddQuad(quad3);

		spriteRenderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

