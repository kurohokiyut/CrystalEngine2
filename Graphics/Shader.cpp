#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

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
        std::cout << "Failed to open shader: "
                  << path
                  << std::endl;

        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();

    return ss.str();
}

GLuint Shader::Compile(GLenum type,
                       const std::string& source)
{
    GLuint shader = glCreateShader(type);

    const char* src = source.c_str();

    glShaderSource(shader,
                   1,
                   &src,
                   nullptr);

    glCompileShader(shader);

    GLint success;

    glGetShaderiv(shader,
                  GL_COMPILE_STATUS,
                  &success);

    if (!success)
    {
        char log[1024];

        glGetShaderInfoLog(shader,
                           sizeof(log),
                           nullptr,
                           log);

        std::cout
            << log
            << std::endl;

        glDeleteShader(shader);

        return 0;
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

    GLuint vertex =
        Compile(GL_VERTEX_SHADER,
                vertexSource);

    GLuint fragment =
        Compile(GL_FRAGMENT_SHADER,
                fragmentSource);

    if (!vertex || !fragment)
        return false;

    m_Program = glCreateProgram();

    glAttachShader(
        m_Program,
        vertex);

    glAttachShader(
        m_Program,
        fragment);

    glLinkProgram(
        m_Program);

    GLint success;

    glGetProgramiv(
        m_Program,
        GL_LINK_STATUS,
        &success);

    if (!success)
    {
        char log[1024];

        glGetProgramInfoLog(
            m_Program,
            sizeof(log),
            nullptr,
            log);

        std::cout
            << log
            << std::endl;

        glDeleteProgram(
            m_Program);

        m_Program = 0;

        return false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return true;
}

void Shader::Use() const
{
    glUseProgram(m_Program);
}

void Shader::Destroy()
{
    if (m_Program != 0)
    {
        glDeleteProgram(m_Program);
        m_Program = 0;
    }
}

void Shader::SetMat4(
    const std::string& name,
    const glm::mat4& matrix
)
{
    GLint location =
        glGetUniformLocation(
            m_Program,
            name.c_str()
        );


    glUniformMatrix4fv(
        location,
        1,
        GL_FALSE,
        glm::value_ptr(matrix)
    );
}

void Shader::SetVec3(
    const std::string& name,
    const glm::vec3& vector
)
{
    GLint location =
        glGetUniformLocation(
            m_Program,
            name.c_str()
        );

    glUniform3fv(
        location,
        1,
        glm::value_ptr(vector)
    );
}