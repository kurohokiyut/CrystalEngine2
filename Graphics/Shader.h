#pragma once

#include <string>

#include <glad/glad.h>

class Shader
{
public:

    Shader();

    ~Shader();

    bool Load(const char* vertexSource,
              const char* fragmentSource);

    void Bind() const;

    void Unbind() const;

    void Destroy();

    GLuint GetProgram() const;

private:

    GLuint m_Program;

    GLuint Compile(
        GLenum type,
        const char* source);
};