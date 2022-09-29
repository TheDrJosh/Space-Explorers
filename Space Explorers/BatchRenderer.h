#pragma once
#include <glm/glm.hpp>
#include <vector>

#define MaxQuads 100


struct Quad
{
public:
	glm::vec3 position;
	float rotation;
	glm::vec2 scale;
	glm::vec4 tintColor;
	uint32_t texture;
	bool flipX, flipY;
	Quad(glm::vec3 position, float rotation, glm::vec2 scale, glm::vec4 tintColor, uint32_t texture, bool flipX, bool flipY);
	Quad() = default;
};



class BatchRenderer
{
public:
	BatchRenderer();
	void AddQuad(Quad quad);
	void render();
private:
	std::vector<Quad> quads;
	uint32_t vertexBuffer, indexBuffer;
	int MaxTextures;
};

