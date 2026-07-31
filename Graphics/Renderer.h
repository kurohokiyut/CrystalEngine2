#pragma once

#include "Shader.h"
#include "Camera.h"
#include "CubeMesh.h"

class Renderer
{
public:

    bool Initialize();

    void Begin();

    void DrawCube();

    void End();

    void Shutdown();

private:

    Shader shader;

    Camera camera;

    CubeMesh cubeMesh;
};