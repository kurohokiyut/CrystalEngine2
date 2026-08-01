#include "CubeMesh.h"

CubeMesh::CubeMesh()
{
}

CubeMesh::~CubeMesh()
{
    Destroy();
}

bool CubeMesh::Initialize()
{
    float vertices[] =
    {
        // Position (x, y, z) + Color (r, g, b) + Normal (x, y, z)
        // Front
        -0.5f,-0.5f, 0.5f,  1.0f,0.2f,0.2f,   0.0f, 0.0f, 1.0f,
         0.5f,-0.5f, 0.5f,  1.0f,0.6f,0.2f,   0.0f, 0.0f, 1.0f,
         0.5f, 0.5f, 0.5f,  1.0f,0.8f,0.2f,   0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f,  0.8f,0.8f,0.2f,   0.0f, 0.0f, 1.0f,

        // Back
        -0.5f,-0.5f,-0.5f,  0.2f,0.2f,1.0f,   0.0f, 0.0f,-1.0f,
         0.5f,-0.5f,-0.5f,  0.2f,0.6f,1.0f,   0.0f, 0.0f,-1.0f,
         0.5f, 0.5f,-0.5f,  0.2f,0.8f,1.0f,   0.0f, 0.0f,-1.0f,
        -0.5f, 0.5f,-0.5f,  0.2f,0.8f,0.8f,   0.0f, 0.0f,-1.0f,

        // Left
        -0.5f,-0.5f,-0.5f,  0.2f,0.2f,1.0f,  -1.0f, 0.0f, 0.0f,
        -0.5f,-0.5f, 0.5f,  1.0f,0.2f,0.2f,  -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,  0.8f,0.8f,0.2f,  -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f,-0.5f,  0.2f,0.8f,0.8f,  -1.0f, 0.0f, 0.0f,

        // Right
         0.5f,-0.5f,-0.5f,  0.2f,0.6f,1.0f,   1.0f, 0.0f, 0.0f,
         0.5f,-0.5f, 0.5f,  1.0f,0.6f,0.2f,   1.0f, 0.0f, 0.0f,
         0.5f, 0.5f, 0.5f,  1.0f,0.8f,0.2f,   1.0f, 0.0f, 0.0f,
         0.5f, 0.5f,-0.5f,  0.2f,0.8f,1.0f,   1.0f, 0.0f, 0.0f,

        // Top
        -0.5f, 0.5f, 0.5f,  0.8f,0.8f,0.2f,   0.0f, 1.0f, 0.0f,
         0.5f, 0.5f, 0.5f,  1.0f,0.8f,0.2f,   0.0f, 1.0f, 0.0f,
         0.5f, 0.5f,-0.5f,  0.2f,0.8f,1.0f,   0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f,-0.5f,  0.2f,0.8f,0.8f,   0.0f, 1.0f, 0.0f,

        // Bottom
        -0.5f,-0.5f, 0.5f,  1.0f,0.2f,0.2f,   0.0f,-1.0f, 0.0f,
         0.5f,-0.5f, 0.5f,  1.0f,0.6f,0.2f,   0.0f,-1.0f, 0.0f,
         0.5f,-0.5f,-0.5f,  0.2f,0.6f,1.0f,   0.0f,-1.0f, 0.0f,
        -0.5f,-0.5f,-0.5f,  0.2f,0.2f,1.0f,   0.0f,-1.0f, 0.0f,
    };

    unsigned int indices[] =
    {
        // Front
        0,1,2,
        2,3,0,

        // Right
        1,5,6,
        6,2,1,

        // Back
        5,4,7,
        7,6,5,

        // Left
        4,0,3,
        3,7,4,

        // Top
        3,2,6,
        6,7,3,

        // Bottom
        4,5,1,
        1,0,4
    };

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW);

    glBindBuffer(
        GL_ELEMENT_ARRAY_BUFFER,
        EBO);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        sizeof(indices),
        indices,
        GL_STATIC_DRAW);

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        9*sizeof(float),
        (void*)0);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        9*sizeof(float),
        (void*)(3*sizeof(float)));

    glEnableVertexAttribArray(1);

    glVertexAttribPointer(
        2,
        3,
        GL_FLOAT,
        GL_FALSE,
        9*sizeof(float),
        (void*)(6*sizeof(float)));

    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    return true;
}

void CubeMesh::Draw()
{
    glBindVertexArray(VAO);

    glDrawElements(
        GL_TRIANGLES,
        36,
        GL_UNSIGNED_INT,
        nullptr);

    glBindVertexArray(0);
}

void CubeMesh::Destroy()
{
    if(EBO)
        glDeleteBuffers(1,&EBO);

    if(VBO)
        glDeleteBuffers(1,&VBO);

    if(VAO)
        glDeleteVertexArrays(1,&VAO);

    VAO=0;
    VBO=0;
    EBO=0;
}