#include "Shader.h"
#include <GL/glew.h>
#include <fstream>
#include <iostream>


uint32_t CompileShader(uint32_t type, const std::string source)
{
	
	uint32_t id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, msg);
		glDeleteShader(id);
		std::string shaderType = (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
		std::cerr << "Failed to compile " + shaderType + " shader" + "\n" + msg << std::endl;
		return 0;
	}

	return id;
}

std::string GetFile(const std::string& filepath)
{
	std::string file = "";
	std::string line;
	std::ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			file += line + "\n";
		}
		myfile.close();
	}
	else std::cout << "Unable to open file " << filepath << std::endl;
	return file;
}



SpaceEngine::Renderer::Shader::Shader()
{
	shaderHandle = 0;
	valid = false;
}
SpaceEngine::Renderer::Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	valid = true;
	const std::string& vertexShader = GetFile(vertexShaderPath);
	const std::string& fragmentShader = GetFile(fragmentShaderPath);
	
	shaderHandle = glCreateProgram();

	uint32_t vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(shaderHandle, vs);
	glAttachShader(shaderHandle, fs);

	glLinkProgram(shaderHandle);
	glValidateProgram(shaderHandle);

	glDeleteShader(vs);
	glDeleteShader(fs);
	use();
}
bool SpaceEngine::Renderer::Shader::isValid()
{
	return valid;
}
void SpaceEngine::Renderer::Shader::use()
{
	glUseProgram(shaderHandle);
}
void SpaceEngine::Renderer::Shader::setMat4(std::string uniformName, glm::mat4 data)
{
	use();
	glUniformMatrix4fv(glGetUniformLocation(shaderHandle, uniformName.c_str()), 1, GL_FALSE, &data[0][0]);
}
void SpaceEngine::Renderer::Shader::setVec4(std::string uniformName, glm::vec4 data)
{
	use();
	glUniform4f(glGetUniformLocation(shaderHandle, uniformName.c_str()), data.x, data.y, data.z, data.w);
}
SpaceEngine::Renderer::Shader::~Shader()
{
	glDeleteProgram(shaderHandle);
}
