#version 330 core

layout(location = 0) in vec2 aPosition;

layout(location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 texCoord;

void main(void)
{
	texCoord = aTexCoord;
	gl_Position =  projection * view * model * vec4(aPosition, 0, 1.0);
}