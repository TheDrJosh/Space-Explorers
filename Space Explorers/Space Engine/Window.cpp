#include "Window.h"
#include <iostream>


SpaceEngine::Window::Window(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		std::cerr << "Error Initilizing GLFW" << std::endl;
		return;
	}

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window)
	{
		std::cerr << "Error Createing Window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	
	
}

bool SpaceEngine::Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void SpaceEngine::Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}
void SpaceEngine::Window::GetSize(int* width, int* height)
{
	glfwGetWindowSize(window, width, height);
}