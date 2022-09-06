#pragma once
#include <cstdint>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Shader.h"
#include "../Window.h"
#include <iostream>
#include "Texture.h"
#include <memory>

namespace ExplorerEngine
{
	namespace Renderer
	{
		struct Quad
		{
			glm::vec2 position = glm::vec2(0, 0);
			float rotation = 0;
			glm::vec2 scale = glm::vec2(1, 1);
			glm::vec4 color = glm::vec4(1,1,1,1);
			Texture texture;
			float depth = 0;


		};

		class SpriteRenderer
		{
		public:
			SpriteRenderer(std::shared_ptr<Window> window);
			void AddQuad(Quad quad);
			void Render();
		private:
			uint32_t vertexBuffer;
			uint32_t indexBuffer;
			std::vector<Quad> quads;
			Shader shader;
			std::shared_ptr<Window> window;
		};

	}
	
}