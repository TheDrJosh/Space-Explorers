#pragma once
#include "ECSCommon.h"
#include <array>
#include <unordered_map>
#include <assert.h>
#include <iostream>

namespace ExplorerEngine
{
	namespace ECS
	{
		class IComponentArray
		{
		public:
			virtual ~IComponentArray() = default;
			virtual void EntityDestroyed(Entity entity) = 0;
		};
		template<typename T>
		class ComponentArray : public IComponentArray
		{
		public:
			void AddComponent(Entity entity, T component)
			{
				if (entityToIndexMap.find(entity) != entityToIndexMap.end())
				{
					std::cout << "Component added to same entity more than once." << std::endl;
					return;
				}

				size_t newIndex = length;
				entityToIndexMap[entity] = newIndex;
				indexToEntityMap[newIndex] = entity;
				componentArray[newIndex] = component;
				length++;
			}
			void RemoveComponent(Entity entity)
			{
				if (entityToIndexMap.find(entity) == entityToIndexMap.end())
				{
					std::cout << "Removing non-existent component." << std::endl;
					return;
				}


				size_t indexOfRemovedEntity = entityToIndexMap[entity];
				size_t indexOfLastElement = length - 1;
				componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

				Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
				entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
				indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

				entityToIndexMap.erase(entity);
				indexToEntityMap.erase(indexOfLastElement);

				length--;
			}
			T& GetComponent(Entity entity)
			{
				if (entityToIndexMap.find(entity) == entityToIndexMap.end())
				{
					std::cout << "Retrieving non-existent component." << std::endl;
					throw;
				}

				return componentArray[entityToIndexMap[entity]];
			}
			void EntityDestroyed(Entity entity) override
			{
				if (entityToIndexMap.find(entity) != entityToIndexMap.end())
				{
					RemoveComponent(entity);
				}
			}

		private:
			std::array<T, MAX_ENTITIES> componentArray;
			std::unordered_map<Entity, size_t> entityToIndexMap;
			std::unordered_map<size_t, Entity> indexToEntityMap;
			size_t length;
		};

	}
}