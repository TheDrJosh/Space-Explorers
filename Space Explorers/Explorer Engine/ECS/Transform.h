#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <entt.hpp>

namespace ExplorerEngine
{
	namespace ECS
	{
		struct Transform
		{
			glm::vec2 position = glm::vec2(0, 0);
			float rotation = 0;
			glm::vec2 scale = glm::vec2(1, 1);
			glm::mat4 modelMatrix = glm::mat4(1);
		};

		void UpdateTransformMatrix(entt::registry& registry, entt::entity entity)
		{
			Transform& transform = registry.get<ECS::Transform>(entity);

			transform.modelMatrix = glm::identity<glm::mat4>();
			transform.modelMatrix = glm::translate(transform.modelMatrix, glm::vec3(transform.position, 0));
			transform.modelMatrix = glm::rotate(transform.modelMatrix, transform.rotation, glm::vec3(0, 0, 1));
			transform.modelMatrix = glm::scale(transform.modelMatrix, glm::vec3(transform.scale, 1));

		}

	}
}
