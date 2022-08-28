#pragma once
#include <string>
#include <glm/glm.hpp>

namespace SpaceEngine
{
	namespace Renderer
	{
		class Shader
		{
		public:
			Shader();
			Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
			bool isValid();
			void use();
			void setMat4(std::string uniformName, glm::mat4 data);
			void setVec4(std::string uniformName, glm::vec4 data);
			~Shader();
		private:
			bool valid;
			uint32_t shaderHandle;
		};
	}
}