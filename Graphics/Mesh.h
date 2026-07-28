#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh
{
public:

    Mesh();
    virtual ~Mesh();

    virtual bool Create(
        const float* vertices,
        unsigned int vertexSize,
        const unsigned int* indices,
        unsigned int indexCount);

    virtual void Draw();

    virtual void Destroy();

protected:

    VertexArray m_VertexArray;

    VertexBuffer m_VertexBuffer;

    IndexBuffer m_IndexBuffer;
};