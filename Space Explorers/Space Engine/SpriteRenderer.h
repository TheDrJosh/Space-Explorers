#pragma once
#include <cstdint>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Shader.h"
#include "Window.h"
#include <iostream>
#include "Texture.h"

namespace SpaceEngine
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

			void print()
			{
				std::cout << 
					"Position: (" << position.x << ", " << position.y << ")" << std::endl <<
					"Rotation: " << rotation << std::endl <<
					"Scale: (" << scale.x << ", " << scale.y << ")" << std::endl <<
					"Color: (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")" << std::endl <<
					"texture: \"" << texture.getName() << "\"" << std::endl <<
					"Depth: " << depth << std::endl;
			}

		};

		class SpriteRenderer
		{
		public:
			SpriteRenderer(Window* window);
			void AddQuad(Quad quad);
			void Render();
		private:
			uint32_t vertexBuffer;
			uint32_t indexBuffer;
			std::vector<Quad> quads;
			Shader shader;
			Window* window;
		};

	}
	
}