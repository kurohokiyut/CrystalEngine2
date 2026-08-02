#version 330 core

in vec3 vColor;
in vec3 vNormal;
in vec3 vFragPos;

uniform vec3 uLightDir;
uniform vec3 uColor;

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
