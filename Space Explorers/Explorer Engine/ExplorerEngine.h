#pragma once
#include "Window.h"
#include "Render/Renderer.h"
#include <memory>

namespace ExplorerEngine
{
	class Engine
	{
	public:
		Engine(int width, int height, const char* title);
		~Engine();
		void start();
		


		

	private:
		std::unique_ptr<Window> window;
		std::unique_ptr<Render::MainRenderer> renderer;
	};
	
}
