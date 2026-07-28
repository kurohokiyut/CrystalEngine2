#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:

    VertexBuffer();
    ~VertexBuffer();

    bool Create(const void* data,
                unsigned int size);

    void Bind() const;

    void Unbind() const;

    void Destroy();

    GLuint GetID() const;

private:

    GLuint m_ID;
};