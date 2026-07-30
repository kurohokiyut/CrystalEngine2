#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <iostream>
#include <sstream>

#include <glad/glad.h>

Shader::Shader()
{
    m_Program = 0;
}

Shader::~Shader()
{
    Destroy();
}

std::string Shader::ReadFile(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cout << "Cannot open shader : "
                  << path
                  << std::endl;

        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();

    return ss.str();
}

unsigned int Shader::CompileShader(
    unsigned int type,
    const std::string& source)
{
    unsigned int shader = glCreateShader(type);

    const char* src = source.c_str();

    glShaderSource(shader, 1, &src, nullptr);

    glCompileShader(shader);

    int success;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char log[1024];

        glGetShaderInfoLog(
            shader,
            1024,
            nullptr,
            log
        );

        std::cout
            << "Shader Compile Error\n"
            << log
            << std::endl;
    }

    return shader;
}

bool Shader::Load(
    const std::string& vertexPath,
    const std::string& fragmentPath)
{
    std::string vertexSource =
        ReadFile(vertexPath);

    std::string fragmentSource =
        ReadFile(fragmentPath);

    unsigned int vertex =
        CompileShader(
            GL_VERTEX_SHADER,
            vertexSource);

    unsigned int fragment =
        CompileShader(
            GL_FRAGMENT_SHADER,
            fragmentSource);

    m_Program = glCreateProgram();

    glAttachShader(m_Program, vertex);
    glAttachShader(m_Program, fragment);

    glLinkProgram(m_Program);

    int success;

    glGetProgramiv(
        m_Program,
        GL_LINK_STATUS,
        &success);

    if (!success)
    {
        char log[1024];

        glGetProgramInfoLog(
            m_Program,
            1024,
            nullptr,
            log);

        std::cout
            << "Program Link Error\n"
            << log
            << std::endl;

        return false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

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

unsigned int Shader::GetProgram() const
{
    return m_Program;
}

void Shader::SetMat4(
    const std::string& name,
    const glm::mat4& matrix)
{
    unsigned int location =
        glGetUniformLocation(
            m_Program,
            name.c_str());

    glUniformMatrix4fv(
        location,
        1,
        GL_FALSE,
        glm::value_ptr(matrix));
}