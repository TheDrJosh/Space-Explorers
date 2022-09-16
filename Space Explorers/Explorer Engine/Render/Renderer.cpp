#include "Renderer.h"

ExplorerEngine::Render::MainRenderer::MainRenderer()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		glfwTerminate();
		std::cerr << glewGetErrorString(err) << std::endl;
		return;
	}
	spriteRenderer = std::make_unique<SpriteRenderer>();
}
void ExplorerEngine::Render::MainRenderer::Render(int width, int height)
{
	spriteRenderer->Render(width, height);
}