#pragma once

#include <glad/glad.h>

class IndexBuffer
{
public:

    IndexBuffer();
    ~IndexBuffer();

    bool Create(
        const unsigned int* data,
        unsigned int count);

    void Bind() const;

    void Unbind() const;

    void Destroy();

    GLuint GetID() const;

    unsigned int GetCount() const;

private:

    GLuint m_ID;

    unsigned int m_Count;
};