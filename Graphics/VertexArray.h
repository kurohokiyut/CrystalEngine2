#pragma once

#include <glad/glad.h>

class VertexArray
{
public:

    VertexArray();
    ~VertexArray();

    bool Create();

    void Bind() const;

    void Unbind() const;

    void EnableAttribute(
        GLuint index,
        GLint size,
        GLenum type,
        GLboolean normalized,
        GLsizei stride,
        const void* pointer);

    void Destroy();

    GLuint GetID() const;

private:

    GLuint m_ID;
};