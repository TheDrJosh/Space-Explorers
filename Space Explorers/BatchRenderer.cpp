#include "BatchRenderer.h"


#include <array>
#include <gl/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <set>


Quad::Quad(glm::vec3 position, float rotation, glm::vec2 scale, glm::vec4 tintColor, uint32_t texture, bool flipX, bool flipY)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	this->tintColor = tintColor;
	this->texture = texture;
	this->flipX = flipX;
	this->flipY = flipY;
}


struct Vertex
{
	glm::vec3 position;
	glm::vec2 uv;
	glm::vec4 color;
	uint32_t texture;
};


BatchRenderer::BatchRenderer()
{
	std::array<uint16_t, MaxQuads * 6> triangles;
	for (int i = 0; i < MaxQuads; i++)
	{
		triangles[i * 6 + 0] = i * 4 + 0;
		triangles[i * 6 + 1] = i * 4 + 1;
		triangles[i * 6 + 2] = i * 4 + 2;
		triangles[i * 6 + 3] = i * 4 + 1;
		triangles[i * 6 + 4] = i * 4 + 3;
		triangles[i * 6 + 5] = i * 4 + 2;
	}

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(struct Vertex, position));
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(struct Vertex, uv));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(struct Vertex, color));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(1, 1, GL_UNSIGNED_INT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(struct Vertex, texture));

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4 * MaxQuads, nullptr, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangles.data()), triangles.data(), GL_STATIC_DRAW);

	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &MaxTextures);
}

void BatchRenderer::AddQuad(Quad quad)
{
	quads.push_back(quad);
}

void renderBuffer(std::array<Vertex, 4 * MaxQuads>& vertices, int& quadCount, std::set<uint32_t>& usedTextures, uint32_t vertexBuffer, uint32_t indexBuffer)
{
	int i = 0;
	for (uint32_t texture : usedTextures)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, texture);
		i++;
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices.data());


	glDrawElements(GL_TRIANGLES, 6 * quadCount, GL_UNSIGNED_SHORT, nullptr);
	

	quadCount = 0;
	usedTextures.clear();

}



void BatchRenderer::render()
{
	int quadCount = 0;
	
	std::array<Vertex, 4 * MaxQuads> vertices;

	std::set<uint32_t> usedTextures;

	while (quads.size() != 0)
	{
		for (int i = quads.size() - 1; i >= 0; i--)
		{
			Quad quad = quads[i];

			if (usedTextures.size() == MaxTextures - 1 && !usedTextures.contains(quad.texture))
				continue;

			Vertex& topRight = vertices[quadCount * 4 + 0];
			Vertex& topLeft = vertices[quadCount * 4 + 1];
			Vertex& bottomRight = vertices[quadCount * 4 + 2];
			Vertex& bottomLeft = vertices[quadCount * 4 + 3];

			glm::mat4 transform = glm::identity<glm::mat4>();
			transform = glm::translate(transform, quads[i].position);
			transform = glm::rotate(transform, quads[i].rotation, glm::vec3(0, 0, 1));
			transform = glm::scale(transform, glm::vec3(quads[i].scale, 1));

			topRight.position = transform * glm::vec4(quads[i].position + glm::vec3(0.5, 0.5, 0), 1);
			topLeft.position = transform * glm::vec4(quads[i].position + glm::vec3(-0.5, 0.5, 0), 1);
			bottomRight.position = transform * glm::vec4(quads[i].position + glm::vec3(0.5, -0.5, 0), 1);
			bottomLeft.position = transform * glm::vec4(quads[i].position + glm::vec3(-0.5, -0.5, 0), 1);

			topRight.uv = glm::vec2(!quads[i].flipX, !quads[i].flipY);
			topLeft.uv = glm::vec2(quads[i].flipX, !quads[i].flipY);
			bottomRight.uv = glm::vec2(!quads[i].flipX, quads[i].flipY);
			bottomLeft.uv = glm::vec2(quads[i].flipX, quads[i].flipY);

			topRight.color = quads[i].tintColor;
			topLeft.color = quads[i].tintColor;
			bottomRight.color = quads[i].tintColor;
			bottomLeft.color = quads[i].tintColor;

			usedTextures.insert(quad.texture);

			uint32_t texLoc = *usedTextures.find(quad.texture);

			topRight.texture = texLoc;
			topLeft.texture = texLoc;
			bottomRight.texture = texLoc;
			bottomLeft.texture = texLoc;

			quadCount++;
			quads.erase(quads.begin() + i);

			if (quadCount == MaxQuads)
				break;

		}
		renderBuffer(vertices, quadCount, usedTextures, vertexBuffer, indexBuffer);
	}

}

