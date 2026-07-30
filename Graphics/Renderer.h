#pragma once

#include "CubeMesh.h"
#include "Shader.h"
#include "Camera.h"

class Renderer
{
public:

    Renderer();
    ~Renderer();

    bool Initialize();

    void Begin();

    void DrawCube();

    void End();

    void Shutdown();

private:

    CubeMesh cubeMesh;

    Shader shader;

    Camera camera;

    CubeMesh* m_Cube;
};