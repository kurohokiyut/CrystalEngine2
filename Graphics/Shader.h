#pragma once
#include <glm/glm.hpp>

#include <string>

class Shader
{
public:

    Shader();
    ~Shader();

    bool Load(
        const std::string& vertexPath,
        const std::string& fragmentPath
    );

    void Bind() const;
    void Unbind() const;

    void Destroy();

    void SetMat4(
    const std::string& name,
    const glm::mat4& matrix
);

    unsigned int GetProgram() const;

private:

    std::string ReadFile(const std::string& path);

    unsigned int CompileShader(
        unsigned int type,
        const std::string& source
    );

private:

    unsigned int m_Program;
};