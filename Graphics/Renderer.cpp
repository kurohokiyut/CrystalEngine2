#include "Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
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

    if (!floorMesh.Initialize())
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

    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = camera.GetProjectionMatrix();

    glm::mat4 floorModel = glm::translate(
        glm::mat4(1.0f),
        glm::vec3(0.0f, 0.0f, 0.0f));

    shader.SetMat4("uModel", floorModel);
    shader.SetMat4("uView", view);
    shader.SetMat4("uProjection", projection);
    shader.SetVec3("uLightDir", glm::normalize(glm::vec3(0.5f, 1.0f, 0.3f)));
    shader.SetVec3("uColor", glm::vec3(1.0f, 1.0f, 1.0f));
    floorMesh.Draw();

    glm::mat4 cubeModel = glm::translate(
        glm::mat4(1.0f),
        glm::vec3(0.0f, 0.5f, 0.0f));

    cubeModel = glm::rotate(
        cubeModel,
        glm::radians(20.0f),
        glm::vec3(1.0f, 0.0f, 0.0f));

    cubeModel = glm::rotate(
        cubeModel,
        glm::radians(30.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));

    shader.SetMat4("uModel", cubeModel);
    shader.SetVec3("uColor", glm::vec3(0.0f, 0.0f, 0.0f));
    cubeMesh.Draw();
}

void Renderer::ProcessInput(GLFWwindow* window, float deltaTime)
{
    camera.ProcessKeyboard(window, deltaTime);
}

void Renderer::End()
{
}

void Renderer::Shutdown()
{
    cubeMesh.Destroy();

    shader.Destroy();
}