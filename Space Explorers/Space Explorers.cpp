#include <gl/glew.h>

#include "Window.h"
#include "BatchRenderer.h"
#include "Texture.h"

#include<iostream>



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

    BatchRenderer batchRenderer;

    Texture texture("container.jpg");

    Quad quad(glm::vec3(0, 0, 0), 0, glm::vec2(1, 1), glm::vec4(1, 1, 1, 1), texture.gpuTexture(), false, false);
    

    glClearColor(0.2, 0.2, 0.2, 1);

    while (!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        batchRenderer.AddQuad(quad);

        batchRenderer.render();


        window.endFrame();
    }



    glfwTerminate();
    return 0;
}
