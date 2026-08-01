#version 330 core

in vec3 vColor;
in vec3 vNormal;
in vec3 vFragPos;

uniform vec3 uLightDir;
uniform vec3 uColor;

out vec4 FragColor;

void main()
{
    vec3 normal = normalize(vNormal);
    vec3 lightDir = normalize(-uLightDir);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * uColor;
    vec3 ambient = 0.25 * uColor;
    vec3 result = (ambient + diffuse) * vColor;
    FragColor = vec4(result, 1.0);
}
