#pragma once
#include <string>


namespace ExplorerEngine
{
	namespace Render
	{
		using GPUTexture = uint32_t;

		class Texture
		{
		public:
			Texture();
			Texture(std::string path);
			void use(int textureUnit);
			std::string getName();
		private:
			std::string name;
			GPUTexture texture;
			int width;
			int height;
		};
	}
}