#pragma once

#include "Shader.h"
#include "Mesh.h"

class Renderer
{
public:

    Renderer();
    ~Renderer();

    bool Initialize();

    void BeginFrame();

    void Draw(
        Shader& shader,
        Mesh& mesh);

    void EndFrame();

    void Shutdown();
};