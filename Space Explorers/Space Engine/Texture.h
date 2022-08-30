#pragma once
#include <string>


namespace SpaceEngine
{
	namespace Renderer
	{
		class Texture
		{
		public:
			Texture();
			Texture(std::string path);
			void use(int textureUnit);
			std::string getName();
		private:
			std::string name;
			uint32_t texture;
			int width;
			int height;
		};
	}
}