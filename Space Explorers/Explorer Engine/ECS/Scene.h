#pragma once
#include "ECSCommon.h"
#include "EntityManager.h"
#include "ComponetManager.h"
namespace ExplorerEngine
{
	namespace ECS
	{
		class Scene
		{
		public:
			Entity CreateEntity()
			{
				return CreateEntity(0);
			}
			Entity CreateEntity(ComponentSet compoentSet)
			{
				Entity id = entityManager.AddEntiy();
				return id;
			}
			Entity Instantiate(Entity entity)
			{
				return 0;
			}
			void DestroyEntity(Entity entity)
			{
				entityManager.RemoveEntity(entity);
				componentManager.EntityDestroyed(entity);
			}
			
			template<typename T>
			void RegisterComponent()
			{
				componentManager.RegisterComponent<T>();
			}
			template<typename T>
			void AddComponent(Entity entity, T component)
			{
				componentManager.AddComponent<T>(entity, component);
			}
			template<typename T>
			void RemoveComponent(Entity entity)
			{
				componentManager.RemoveCompoent<T>(entity);
			}
			template<typename T>
			T& GetCompoent(Entity entity)
			{
				return componentManager.GetCompoent<T>(entity);
			}
		private:
			EntityManager entityManager;
			ComponentManager componentManager;
		};
		
	}
}