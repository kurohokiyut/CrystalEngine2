#include "Renderer.h"
#include "CubeMesh.h"
#include <glad/glad.h>

Renderer::Renderer()
{
    m_Cube = nullptr;
}

Renderer::~Renderer()
{
}

bool Renderer::Initialize()
{
    glEnable(GL_DEPTH_TEST);

    glClearColor(
        0.15f,
        0.15f,
        0.18f,
        1.0f
    );

    return true;

       shader.Load(
        "Assets/Shaders/Default.vert",
        "Assets/Shaders/Default.frag"
    );

    camera.Initialize(
        1280.0f,
        720.0f
    );

    cubeMesh.Initialize();

    return true;
}

void Renderer::Begin()
{
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );
}

void Renderer::DrawCube()
{
    shader.Bind();

    glm::mat4 model(1.0f);

    shader.SetMat4(
        "uModel",
        model);

    shader.SetMat4(
        "uView",
        camera.GetViewMatrix());

    shader.SetMat4(
        "uProjection",
        camera.GetProjectionMatrix());

    cubeMesh.Draw();
}

void Renderer::End()
{

}

void Renderer::Shutdown()
{
    if(m_Cube)
    {
        m_Cube->Shutdown();
    }
}

void CubeMesh::Draw()
{
    glBindVertexArray(VAO);

    glDrawElements(
        GL_TRIANGLES,
        36,
        GL_UNSIGNED_INT,
        nullptr
    );

    glBindVertexArray(0);
}


void CubeMesh::Shutdown()
{
    if(EBO)
        glDeleteBuffers(1, &EBO);

    if(VBO)
        glDeleteBuffers(1, &VBO);

    if(VAO)
        glDeleteVertexArrays(1, &VAO);


    VAO = 0;
    VBO = 0;
    EBO = 0;
}