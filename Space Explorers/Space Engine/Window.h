#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

namespace SpaceEngine
{
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		bool ShouldClose();
		void SwapBuffers();
		void GetSize(int* width, int* height);
	//private:
		GLFWwindow* window;
	};
}

