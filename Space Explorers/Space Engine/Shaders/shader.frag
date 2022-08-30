#version 330

out vec4 outputColor;

in vec2 texCoord;

uniform sampler2D texture0;

uniform vec4 color;

void main()
{
	outputColor = color * texture(texture0, texCoord);
}