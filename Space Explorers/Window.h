#pragma once
#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, std::string title);
	bool shouldClose();
	void endFrame();

private:
	GLFWwindow* window;

};

