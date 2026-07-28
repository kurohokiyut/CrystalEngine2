//======================================================
// CrystalEngine
// Shader.cpp
//======================================================

#include "Shader.h"

#include <iostream>

Shader::Shader()
{
    m_Program = 0;
}

Shader::~Shader()
{
    Destroy();
}

GLuint Shader::Compile(GLenum type, const char* source)
{
    GLuint shader = glCreateShader(type);

    glShaderSource(shader,
                   1,
                   &source,
                   nullptr);

    glCompileShader(shader);

    GLint success = GL_FALSE;

    glGetShaderiv(shader,
                  GL_COMPILE_STATUS,
                  &success);

    if (!success)
    {
        char log[2048];

        glGetShaderInfoLog(shader,
                           sizeof(log),
                           nullptr,
                           log);

        std::cout
            << "==============================\n";

        if (type == GL_VERTEX_SHADER)
        {
            std::cout
                << "Vertex Shader Compile Error\n";
        }
        else
        {
            std::cout
                << "Fragment Shader Compile Error\n";
        }

        std::cout
            << log
            << std::endl;

        glDeleteShader(shader);

        return 0;
    }

    return shader;
}

bool Shader::Load(
    const char* vertexSource,
    const char* fragmentSource)
{
    GLuint vertex =
        Compile(
            GL_VERTEX_SHADER,
            vertexSource);

    if (vertex == 0)
        return false;

    GLuint fragment =
        Compile(
            GL_FRAGMENT_SHADER,
            fragmentSource);

    if (fragment == 0)
    {
        glDeleteShader(vertex);
        return false;
    }

    m_Program = glCreateProgram();

    glAttachShader(
        m_Program,
        vertex);

    glAttachShader(
        m_Program,
        fragment);

    glLinkProgram(
        m_Program);

    GLint success = GL_FALSE;

    glGetProgramiv(
        m_Program,
        GL_LINK_STATUS,
        &success);

    if (!success)
    {
        char log[2048];

        glGetProgramInfoLog(
            m_Program,
            sizeof(log),
            nullptr,
            log);

        std::cout
            << "==============================\n";

        std::cout
            << "Shader Link Error\n";

        std::cout
            << log
            << std::endl;

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        glDeleteProgram(m_Program);

        m_Program = 0;

        return false;
    }

    glDetachShader(
        m_Program,
        vertex);

    glDetachShader(
        m_Program,
        fragment);

    glDeleteShader(vertex);

    glDeleteShader(fragment);

    std::cout
        << "[Shader] Successfully Compiled\n";

    return true;
}

void Shader::Bind() const
{
    glUseProgram(m_Program);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::Destroy()
{
    if (m_Program != 0)
    {
        glDeleteProgram(m_Program);

        m_Program = 0;
    }
}

GLuint Shader::GetProgram() const
{
    return m_Program;
}