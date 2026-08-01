#include "Renderer.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

bool Renderer::Initialize()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    if (!shader.Load(
        "Assets/Shaders/Basic.vert",
        "Assets/Shaders/Basic.frag"))
    {
        return false;
    }

    if (!cubeMesh.Initialize())
    {
        return false;
    }

    camera.Initialize(1280.0f, 720.0f);

    return true;
}

void Renderer::Begin()
{
    glClearColor(
        0.529f,
        0.808f,
        0.922f,
        1.0f);

    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT);

    shader.Use();
}

void Renderer::DrawCube()
{
    shader.Use();

    glm::mat4 model = glm::translate(
        glm::mat4(1.0f),
        glm::vec3(0.0f, 0.0f, -2.5f));

    model = glm::rotate(
        model,
        glm::radians(35.0f),
        glm::vec3(1.0f, 0.0f, 0.0f));

    model = glm::rotate(
        model,
        glm::radians(35.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = camera.GetProjectionMatrix();

    shader.SetMat4("uModel", model);
    shader.SetMat4("uView", view);
    shader.SetMat4("uProjection", projection);
    shader.SetVec3("uLightDir", glm::normalize(glm::vec3(0.5f, 1.0f, 0.3f)));
    shader.SetVec3("uColor", glm::vec3(1.0f, 1.0f, 1.0f));

    cubeMesh.Draw();
}

void Renderer::End()
{
}

void Renderer::Shutdown()
{
    cubeMesh.Destroy();

    shader.Destroy();
}