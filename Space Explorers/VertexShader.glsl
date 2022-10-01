#version 330 core

layout(location = 0) in vec3 aPosition;

layout(location = 1) in vec2 aTexCoord;

layout(location = 2) in vec4 aTintColor;

layout(location = 3) in uint aTextureID;

//uniform mat4 view;
//uniform mat4 projection;
//
//out vec2 oTexCoord;
//out vec4 oTintColor;
//out uint oTextureID;
//

void main()
{
	//oTexCoord = aTexCoord;
	//oTintColor = aTintColor;
	//oTextureID = aTextureID;
	//gl_Position =  projection * view * vec4(aPosition, 1.0);
	gl_Position =  vec4(aPosition, 1.0);
}