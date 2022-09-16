#include "Scene.h"

namespace ExplorerEngine
{
	namespace ECS
	{
		Scene::Scene()
		{

		}
		entt::entity Scene::CreateEntity()
		{
			return registry.create();
		}
		void Scene::DestroyEntity(entt::entity entity)
		{
			registry.destroy(entity);
		}
	}
}