//======================================================
// CrystalEngine
// CubeMesh.cpp
//======================================================

#include "CubeMesh.h"

CubeMesh::CubeMesh()
{
    VAO = 0;
    VBO = 0;
    EBO = 0;
}

CubeMesh::~CubeMesh()
{
    Shutdown();
}

bool CubeMesh::Create(
    const float* vertices,
    size_t vertexSize,
    const unsigned int* indices,
    size_t indexCount
)
{
    return true;
}

bool CubeMesh::Initialize(){

    static const float vertices[] =
    {
        // Back
        -0.5f,-0.5f,-0.5f,
         0.5f,-0.5f,-0.5f,
         0.5f, 0.5f,-0.5f,
        -0.5f, 0.5f,-0.5f,

        // Front
        -0.5f,-0.5f, 0.5f,
         0.5f,-0.5f, 0.5f,
         0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f
    };

    static const unsigned int indices[] =
    {
        // Front
        4,5,6,
        6,7,4,

        // Back
        0,1,2,
        2,3,0,

        // Left
        0,4,7,
        7,3,0,

        // Right
        1,5,6,
        6,2,1,

        // Top
        3,7,6,
        6,2,3,

        // Bottom
        0,1,5,
        5,4,0
    };

    return Create(
        vertices,
        sizeof(vertices),
        indices,
        sizeof(indices) / sizeof(unsigned int));
}