#include "Window.h"
#include <stdexcept>

Window::Window(int width, int height, std::string title)
{
#ifdef _DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif // DEBUG


	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);



	if (!window)
	{
		glfwTerminate();
		throw std::runtime_error("Failed To Initalize GLFW Window!");
	}

	glfwMakeContextCurrent(window);




}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::endFrame()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}
