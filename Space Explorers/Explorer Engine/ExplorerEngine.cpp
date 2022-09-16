#include "ExplorerEngine.h"



ExplorerEngine::Engine::Engine(int width, int height, const char* title)
{
	window = std::make_unique<Window>(width, height, title);
	renderer = std::make_unique<Render::MainRenderer>();

	sceneManager.RegisterComponent<ECS::Transform>();
	sceneManager.RegisterComponent<ECS::SpriteRenderer>();

}

ExplorerEngine::Engine::~Engine()
{
	glfwTerminate();
}
void ExplorerEngine::Engine::start()
{
	int width, height = 0;

	while (!window->ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		window->GetSize(&width, &height);

		renderer->Render(width, height);

		window->SwapBuffers();
		glfwPollEvents();
	}
}

ExplorerEngine::ECS::SceneID ExplorerEngine::Engine::AddScene()
{
	return sceneManager.AddScene();
}

void ExplorerEngine::Engine::RemoveScene(ECS::SceneID scene)
{
	sceneManager.RemoveScene(scene);
}

void ExplorerEngine::Engine::ActiveScene(ECS::SceneID scene)
{
	sceneManager.SetActive(scene);
}

void ExplorerEngine::Engine::SetSequence(std::vector<ECS::SceneID> sequence)
{
	sceneManager.SetSequence(sequence);
}
void ExplorerEngine::Engine::AddToSequence(ECS::SceneID scene)
{
	sceneManager.AddToSequence(scene);
}
void ExplorerEngine::Engine::SaveScene(ECS::SceneID scene)
{
	sceneManager.SaveScene(scene);
}

ExplorerEngine::ECS::Entity ExplorerEngine::Engine::AddEntity()
{
	return sceneManager.activeScene.CreateEntity();
}


void ExplorerEngine::Engine::RemoveEntity(ECS::Entity entity)
{
	sceneManager.activeScene.DestroyEntity(entity);
}

