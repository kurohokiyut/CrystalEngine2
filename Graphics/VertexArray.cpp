//======================================================
// CrystalEngine
// VertexArray.cpp
//======================================================

#include "VertexArray.h"

#include <iostream>

VertexArray::VertexArray()
{
    m_ID = 0;
}

VertexArray::~VertexArray()
{
    Destroy();
}

bool VertexArray::Create()
{
    if (m_ID != 0)
    {
        Destroy();
    }

    glGenVertexArrays(1, &m_ID);

    if (m_ID == 0)
    {
        std::cout
            << "[VertexArray] Failed to create VAO."
            << std::endl;

        return false;
    }

    std::cout
        << "[VertexArray] Created (ID="
        << m_ID
        << ")"
        << std::endl;

    return true;
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_ID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::EnableAttribute(
    GLuint index,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLsizei stride,
    const void* pointer)
{
    glVertexAttribPointer(
        index,
        size,
        type,
        normalized,
        stride,
        pointer);

    glEnableVertexAttribArray(index);
}

void VertexArray::Destroy()
{
    if (m_ID != 0)
    {
        glDeleteVertexArrays(1, &m_ID);

        std::cout
            << "[VertexArray] Destroyed."
            << std::endl;

        m_ID = 0;
    }
}

GLuint VertexArray::GetID() const
{
    return m_ID;
}