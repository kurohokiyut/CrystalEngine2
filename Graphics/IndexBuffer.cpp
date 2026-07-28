//======================================================
// CrystalEngine
// IndexBuffer.cpp
//======================================================

#include "IndexBuffer.h"

#include <iostream>

IndexBuffer::IndexBuffer()
{
    m_ID = 0;
    m_Count = 0;
}

IndexBuffer::~IndexBuffer()
{
    Destroy();
}

bool IndexBuffer::Create(
    const unsigned int* data,
    unsigned int count)
{
    if (m_ID != 0)
    {
        Destroy();
    }

    m_Count = count;

    glGenBuffers(1, &m_ID);

    if (m_ID == 0)
    {
        std::cout
            << "[IndexBuffer] Failed to create EBO."
            << std::endl;

        return false;
    }

    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        m_ID);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        count * sizeof(unsigned int),
        data,
        GL_STATIC_DRAW);

    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        0);

    std::cout
        << "[IndexBuffer] Created (ID="
        << m_ID
        << ", Count="
        << m_Count
        << ")"
        << std::endl;

    return true;
}

void IndexBuffer::Bind() const
{
    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        m_ID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        0);
}

void IndexBuffer::Destroy()
{
    if (m_ID != 0)
    {
        glDeleteBuffers(
            1,
            &m_ID);

        std::cout
            << "[IndexBuffer] Destroyed."
            << std::endl;

        m_ID = 0;
        m_Count = 0;
    }
}

GLuint IndexBuffer::GetID() const
{
    return m_ID;
}

unsigned int IndexBuffer::GetCount() const
{
    return m_Count;
}