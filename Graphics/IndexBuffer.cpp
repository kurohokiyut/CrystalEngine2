#include "IndexBuffer.h"


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
    unsigned int count
)
{
    m_Count = count;

    glGenBuffers(
        1,
        &m_ID
    );

    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        m_ID
    );

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        count * sizeof(unsigned int),
        data,
        GL_STATIC_DRAW
    );

    return true;
}


void IndexBuffer::Bind() const
{
    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        m_ID
    );
}


void IndexBuffer::Unbind() const
{
    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        0
    );
}


void IndexBuffer::Destroy()
{
    if(m_ID != 0)
    {
        glDeleteBuffers(
            1,
            &m_ID
        );

        m_ID = 0;
    }

    m_Count = 0;
}


GLuint IndexBuffer::GetID() const
{
    return m_ID;
}


unsigned int IndexBuffer::GetCount() const
{
    return m_Count;
}