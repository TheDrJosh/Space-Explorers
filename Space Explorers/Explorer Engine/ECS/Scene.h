#pragma once
#include <entt.hpp>
namespace ExplorerEngine
{
	namespace ECS
	{
		class Scene
		{
		public:
			Scene()
			{

			}
			
			entt::entity CreateEntity()
			{
				return registry.create();
			}
			

		private:
			entt::registry registry;
		};
	}
}