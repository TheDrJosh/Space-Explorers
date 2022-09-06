#pragma once
#include "ECSCommon.h"
#include <queue>
#include <bitset>

#include <iostream>

namespace ExplorerEngine
{
	namespace ECS
	{
		class EntityManager
		{
		public:
			EntityManager()
			{
				for (Entity entity = 0; entity < MAX_ENTITIES; entity++)
				{
					availableEntities.push(entity);
				}
			}
			Entity AddEntiy()
			{
				if (livingEntityCount >= MAX_ENTITIES)
				{
					throw "Max Entitys Reached!";
				}

				Entity id = availableEntities.front();
				availableEntities.pop();
				livingEntityCount++;
				livingEntities[id] = true;

				return id;
			}
			void RemoveEntity(Entity entity)
			{
				if (entity >= MAX_ENTITIES)
				{
					throw "Invalid Entity!";
				}

				if (livingEntities[entity] == true)
				{
					availableEntities.push(entity);
					livingEntities[entity] = false;
					livingEntityCount--;
				}

			}

			
		private:
			std::queue<Entity> availableEntities;
			std::bitset<MAX_ENTITIES> livingEntities;
			uint32_t livingEntityCount = 0;
		};
	}
}