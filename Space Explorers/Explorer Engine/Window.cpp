#include "Window.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

ExplorerEngine::Window::Window(int width, int height, const char* title)
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
	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

bool ExplorerEngine::Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void ExplorerEngine::Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}
void ExplorerEngine::Window::GetSize(int* width, int* height)
{
	glfwGetWindowSize(window, width, height);
}

