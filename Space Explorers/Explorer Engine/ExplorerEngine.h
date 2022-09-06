#pragma once
#include "Window.h"
#include "Render/SpriteRenderer.h"
#include <memory>

namespace ExplorerEngine
{
	class Engine
	{
	public:
		Engine(int width, int height, const char* title)
		{
			window = std::make_shared<Window>(width, height, title);
			spriteRenderer = std::make_unique<Renderer::SpriteRenderer>(window);
		}
		
		void start()
		{
			while (!window->ShouldClose())
			{
				glClear(GL_COLOR_BUFFER_BIT);


				window->SwapBuffers();
				glfwPollEvents();
			}
		}
		~Engine()
		{
			glfwTerminate();
		}

	private:
		std::shared_ptr<Window> window;
		std::unique_ptr< Renderer::SpriteRenderer> spriteRenderer;
	};
}
