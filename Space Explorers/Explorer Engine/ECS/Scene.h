#pragma once
#include <entt.hpp>
namespace ExplorerEngine
{
	namespace ECS
	{
		class Scene
		{
		public:
			Scene();
			
			entt::entity CreateEntity();
			void DestroyEntity(entt::entity entity);
			template<typename T>
			T& AddComponent(entt::entity entity)
			{
				return registry.emplace<T>(entity);
			}
			template<typename T>
			void RemoveComponent(entt::entity entity)
			{
				registry.remove<T>(entity);
			}
			template<typename T>
			T& RemoveComponent(entt::entity entity)
			{
				return registry.get<T>(entity);
			}
			
			

		private:
			entt::registry registry;
		};
	}
}