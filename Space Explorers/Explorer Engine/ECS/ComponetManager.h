#pragma once
#include "ECSCommon.h"
#include "ComponentArray.h"
#include <unordered_map>
#include <memory>
#include <iostream>

namespace ExplorerEngine
{
	namespace ECS
	{
		class ComponentManager
		{
		public:
			template<typename T>
			void RegisterComponent()
			{
				const char* typeName = typeid(T).name();
				if (componentTypes.find(typeName) != componentTypes.end())
				{
					std::cout << "Registering component type more than once." << std::endl;
					return;
				}
				
				componentTypes.insert({ typeName, nextComponentType });
				componentArrays.insert({ typeName, std::make_shared<ComponentArray<T>>() });
				nextComponentType++;
			
			}
			
			template<typename T>
			ComponentType GetComponentType()
			{
				const char* typeName = typeid(T).name();
				if (componentTypes.find(typeName) == componentTypes.end())
				{
					std::cout << "Component not registered before use." << std::endl;
					return;
				}
			
				return componentTypes[typeName];
			}
			
			template<typename T>
			void AddComponent(Entity entity, T component)
			{
				GetComponentArray<T>()->AddComponent(entity, component);

				ComponentSet componentSet = componentSets[entity];
				ComponentSet.set(GetComponentType<T>(), true);
				componentSets[entity] = componentSet;
			}
			
			template<typename T>
			void RemoveCompoent(Entity entity)
			{
				GetComponentArray<T>()->RemoveComponent(entity);

				ComponentSet componentSet = componentSets[entity];
				ComponentSet.set(GetComponentType<T>(), false);
				componentSets[entity] = componentSet;
			}
			
			template<typename T>
			T& GetCompoent(Entity entity)
			{
				return GetComponentArray<T>()->GetComponent(entity);
			}
			
			void EntityDestroyed(Entity entity)
			{
				for (auto const& pair : componentArrays)
				{
					auto const& component = pair.second;
					component->EntityDestroyed(entity);
				}
			}
			
			ComponentSet getComponentSet(Entity entity)
			{
				return componentSets[entity];
			}

		private:
			std::unordered_map<const char*, ComponentType> componentTypes{};
			std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};
			ComponentType nextComponentType;
			std::array<ComponentSet, MAX_ENTITIES> componentSets;

			template<typename T>
			std::shared_ptr<ComponentArray<T>> GetComponentArray()
			{
				const char* typeName = typeid(T).name();
				if (componentTypes.find(typeName) == componentTypes.end())
				{
					std::cout << "Component not registered before use." << std::endl;
				}
			
				return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
			}


		};
	}
}