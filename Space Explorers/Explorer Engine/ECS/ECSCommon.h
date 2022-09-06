#pragma once
#include <stdint.h>
#include <bitset>

namespace ExplorerEngine
{
	namespace ECS
	{
		using Entity = uint32_t;
		const uint32_t MAX_ENTITIES = 1000;
		using ComponentType = uint8_t;
		const uint8_t MAX_COMPONENTS = 32;
		using ComponentSet = std::bitset<MAX_COMPONENTS>;
		const uint8_t MAX_SCENES = 32;
		using SceneID = uint8_t;

	}
}