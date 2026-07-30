#pragma once
#include <cstddef>

class CubeMesh
{
public:

    CubeMesh();
    ~CubeMesh();

    bool Initialize();

    void Draw();

    void Shutdown();

    bool Create(
    const float* vertices,
    size_t vertexSize,
    const unsigned int* indices,
    size_t indexCount
);

private:

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
};