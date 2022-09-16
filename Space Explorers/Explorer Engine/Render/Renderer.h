#pragma once
#include "SpriteRenderer.h"
#include <memory>

namespace ExplorerEngine
{
	namespace Render
	{
		class MainRenderer
		{
		public:
			MainRenderer();

			void Render(int width, int height);
			



		private:
			std::unique_ptr<SpriteRenderer> spriteRenderer;
		};
	}
}