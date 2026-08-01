#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:

    Shader();
    ~Shader();

    bool Load(const std::string& vertexPath,
              const std::string& fragmentPath);

    void Use() const;

    void Destroy();

    unsigned int GetProgram() const
    {
        return m_Program;

    }

    void SetMat4(
        const std::string& name,
        const glm::mat4& matrix
    );

    void SetVec3(
        const std::string& name,
        const glm::vec3& vector
    );

private:

    std::string ReadFile(const std::string& path);

    GLuint Compile(GLenum type,
                   const std::string& source);

private:

    GLuint m_Program;
};

