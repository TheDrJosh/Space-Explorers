#version 330

out vec4 outputColor;

in vec2 texCoord;

//uniform sampler2D texture0;

uniform vec4 color;

void main()
{
	outputColor = color;//vec4(1,1,0,1);//texture(texture0, texCoord);
}