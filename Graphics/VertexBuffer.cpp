//======================================================
// CrystalEngine
// VertexBuffer.cpp
//======================================================

#include "VertexBuffer.h"

#include <iostream>

VertexBuffer::VertexBuffer()
{
    m_ID = 0;
}

VertexBuffer::~VertexBuffer()
{
    Destroy();
}

bool VertexBuffer::Create(
    const void* data,
    unsigned int size)
{
    if (m_ID != 0)
    {
        Destroy();
    }

    glGenBuffers(1, &m_ID);

    if (m_ID == 0)
    {
        std::cout
            << "[VertexBuffer] Failed to create VBO."
            << std::endl;

        return false;
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_ID);

    glBufferData(
        GL_ARRAY_BUFFER,
        size,
        data,
        GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    std::cout
        << "[VertexBuffer] Created (ID="
        << m_ID
        << ")"
        << std::endl;

    return true;
}

void VertexBuffer::Bind() const
{
    glBindBuffer(
        GL_ARRAY_BUFFER,
        m_ID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(
        GL_ARRAY_BUFFER,
        0);
}

void VertexBuffer::Destroy()
{
    if (m_ID != 0)
    {
        glDeleteBuffers(
            1,
            &m_ID);

        std::cout
            << "[VertexBuffer] Destroyed."
            << std::endl;

        m_ID = 0;
    }
}

GLuint VertexBuffer::GetID() const
{
    return m_ID;
}