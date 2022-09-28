#include <gl/glew.h>

#include "Window.h"

int main()
{

    if (!glfwInit())
        return -1;
    
    Window window(1280, 720, "Space Explorers");

    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return -1;
    }

    glClearColor(0.2, 0.2, 0.2, 1);

    while (!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);


        window.endFrame();
    }



    glfwTerminate();
    return 0;
}
