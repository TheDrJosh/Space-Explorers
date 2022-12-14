#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

namespace ExplorerEngine
{
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		bool ShouldClose();
		void SwapBuffers();
		void GetSize(int* width, int* height);
		~Window();
	private:
		GLFWwindow* window;
	};
}

