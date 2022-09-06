#include "SpriteRenderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

//#define MaxQuads 100

struct Vertex
{
	glm::vec3 position;
	glm::vec2 uv;
	glm::vec4 color;
	uint8_t texture;
};


ExplorerEngine::Renderer::SpriteRenderer::SpriteRenderer(std::shared_ptr<Window> window)
{
	this->window = window;

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		glfwTerminate();
		std::cerr << glewGetErrorString(err) << std::endl;
		return;
	}

	float verts[] = {
		 0.5,  0.5, 1, 1,
		 0.5, -0.5, 1, 0,
		-0.5, -0.5, 0, 0,
		-0.5,  0.5, 0, 1
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)(sizeof(float) * 2));

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	shader = Shader("Explorer Engine/Shaders/shader.vert", 
		"Explorer Engine/Shaders/shader.frag");

	
}
void ExplorerEngine::Renderer::SpriteRenderer::AddQuad(Quad quad)
{
	quads.push_back(quad);
}

bool quadSort(ExplorerEngine::Renderer::Quad i, ExplorerEngine::Renderer::Quad j)
{
	return i.depth > j.depth;
}

void ExplorerEngine::Renderer::SpriteRenderer::Render()
{
	std::sort(quads.begin(), quads.end(), quadSort);

	while (quads.size() != 0)
	{
		Quad quad = quads.back();

		glm::mat4 model = glm::identity<glm::mat4>();
		model = glm::translate(model, glm::vec3(quad.position, 0));
		model = glm::rotate(model, quad.rotation, glm::vec3(0, 0, 1));
		model = glm::scale(model, glm::vec3(quad.scale, 1));

		glm::mat4 view = glm::identity<glm::mat4>();

		int width = 0;
		int height = 0;
		window->GetSize(&width, &height);
		float aspect = (float)height / (float)width;

		float camerascale = 5;

		glm::mat4 projection = glm::ortho(-camerascale, camerascale, -camerascale * aspect, camerascale * aspect, -5000.f, 5000.f);

		shader.use();
		shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);

		shader.setVec4("color", quad.color);


		quad.texture.use(0);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		quads.pop_back();
	}
	

}