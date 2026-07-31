#include "Renderer.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

bool Renderer::Initialize()
{
    glEnable(GL_DEPTH_TEST);

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

    return true;
}

void Renderer::Begin()
{
    glClearColor(
        0.05f,
        0.05f,
        0.05f,
        1.0f);

    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT);

    shader.Use();
}

void Renderer::DrawCube()
{
    shader.Use();

    glm::mat4 model =
        glm::mat4(1.0f);

    glm::mat4 view =
        glm::lookAt(

            glm::vec3(
                0.0f,
                0.0f,
                3.0f),

            glm::vec3(
                0.0f,
                0.0f,
                0.0f),

            glm::vec3(
                0.0f,
                1.0f,
                0.0f)
        );

    glm::mat4 projection =
        glm::perspective(

            glm::radians(45.0f),

            1280.0f / 720.0f,

            0.1f,

            100.0f
        );

    glm::mat4 mvp =
        projection *
        view *
        model;

    shader.SetMat4(
        "uMVP",
        mvp);

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