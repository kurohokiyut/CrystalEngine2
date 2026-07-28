//======================================================
// CrystalEngine
// Mesh.cpp
//======================================================

#include "Mesh.h"

#include <iostream>

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
    Destroy();
}

bool Mesh::Create(
    const float* vertices,
    unsigned int vertexSize,
    const unsigned int* indices,
    unsigned int indexCount)
{
    //----------------------------------------
    // Create VAO
    //----------------------------------------

    if (!m_VertexArray.Create())
    {
        return false;
    }

    //----------------------------------------
    // Bind VAO
    //----------------------------------------

    m_VertexArray.Bind();

    //----------------------------------------
    // Create Vertex Buffer
    //----------------------------------------

    if (!m_VertexBuffer.Create(
        vertices,
        vertexSize))
    {
        return false;
    }

    //----------------------------------------
    // Create Index Buffer
    //----------------------------------------

    if (!m_IndexBuffer.Create(
        indices,
        indexCount))
    {
        return false;
    }

    //----------------------------------------
    // Vertex Layout
    //----------------------------------------

    m_VertexArray.EnableAttribute(
        0,                  // location
        3,                  // xyz
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        (void*)0);

    //----------------------------------------
    // Finish
    //----------------------------------------

    m_VertexArray.Unbind();

    std::cout
        << "[Mesh] Created Successfully."
        << std::endl;

    return true;
}

void Mesh::Draw()
{
    m_VertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        m_IndexBuffer.GetCount(),
        GL_UNSIGNED_INT,
        nullptr);

    m_VertexArray.Unbind();
}

void Mesh::Destroy()
{
    m_IndexBuffer.Destroy();

    m_VertexBuffer.Destroy();

    m_VertexArray.Destroy();

    std::cout
        << "[Mesh] Destroyed."
        << std::endl;
}