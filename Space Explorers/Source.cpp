#include <iostream>
#include <glm/ext/scalar_constants.hpp>
#include "Explorer Engine/ExplorerEngine.h"

using namespace ExplorerEngine;

int main()
{
	/*
	Window window(1920, 1080, "Space Explorer");
	
	Renderer::SpriteRenderer spriteRenderer(&window);
	
	Renderer::Texture texture("D:/Dev/cpp Games/Space Explorers/Space Explorers/container.jpg");

	Renderer::Quad quad;
	quad.rotation = glm::pi<float>() / 4;
	quad.scale = glm::vec2(2, 1);
	quad.position = glm::vec2(1, -1);
	quad.color = glm::vec4(1, 0, 1, 1);
	quad.depth = -1;
	
	Renderer::Quad quad2;
	quad2.position = glm::vec2(0, -1);
	quad2.scale = glm::vec2(2, 1);
	quad2.color = glm::vec4(1, 1, 0, 1);
	
	Renderer::Quad quad3;
	quad3.position = glm::vec2(0, 1);
	quad3.scale = glm::vec2(2, 2);
	quad3.texture = texture;


	ECS::Scene scene;


	scene.RegisterComponent<Transform>();


	ECS::Entity entity1 = scene.CreateEntity();
	Transform transform;
	transform.rotation = 2;
	scene.AddComponent<Transform>(entity1, transform);

	
	Transform entity1_transform = scene.GetCompoent<Transform>(entity1);
	
	entity1_transform.rotation = -2;

	std::cout << entity1_transform.rotation << std::endl;

	Transform entity1_transform2 = scene.GetCompoent<Transform>(entity1);
	std::cout << entity1_transform2.rotation << std::endl;


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
	*/

	Engine engine(1920, 1080, "Space Explorers");

	


	engine.start();

	return 0;
}

