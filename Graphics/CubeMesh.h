#pragma once

#include <glad/glad.h>

class CubeMesh
{
public:

    CubeMesh();
    ~CubeMesh();

    bool Initialize();

    void Draw();

    void Destroy();

private:

    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
};