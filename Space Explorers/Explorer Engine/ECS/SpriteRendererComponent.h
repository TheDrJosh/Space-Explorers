#pragma once
#include <glm/glm.hpp>
#include "../CommonType.h"

namespace ExplorerEngine
{
	namespace ECS
	{
		struct SpriteRenderer
		{
			glm::vec4 color = glm::vec4(1, 1, 1, 1);
			GPUTexture texture;
			bool flipX = false;
			bool flipY = false;
		};

		

	}
}


