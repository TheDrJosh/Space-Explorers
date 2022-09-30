#include "ExplorerEngine.h"
#include "ECS/Transform.h"

namespace ExplorerEngine
{
	Engine::Engine(int width, int height, const char* title)
	{
		window = std::make_unique<Window>(width, height, title);
		renderer = std::make_unique<Render::MainRenderer>();
		
		registry.on_update<ECS::Transform>().connect<&ECS::UpdateTransformMatrix>();

	}

	Engine::~Engine()
	{
		glfwTerminate();
	}
	void Engine::start()
	{
		int width, height = 0;

		while (!window->ShouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT);

			window->GetSize(&width, &height);

			renderer->Render(width, height);

			window->SwapBuffers();
			glfwPollEvents();
		}
	}

}

