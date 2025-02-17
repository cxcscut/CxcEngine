#version 430 core

// Only receive vertex pos
layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 depthMVP;
out vec3 Position_worldspace;

void main()
{
	gl_Position = depthMVP * vec4(vertexPosition_modelspace,1);
}