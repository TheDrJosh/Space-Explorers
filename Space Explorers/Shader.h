#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
	void use();
	void setBool(const std::string& name, bool value) const;

	void setInt(const std::string& name, int value) const;

	void setFloat(const std::string& name, float value) const;

	void setVec2(const std::string& name, glm::vec2 value) const;

	void setVec3(const std::string& name, glm::vec3 value) const;

	void setVec4(const std::string& name, glm::vec4 value) const;

	void setMat4(const std::string& name, glm::mat4 value) const;

private:
	uint32_t ID;
	void checkCompileErrors(unsigned int shader, std::string type);



	
};

