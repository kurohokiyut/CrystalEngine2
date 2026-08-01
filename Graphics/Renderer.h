#pragma once

#include "Shader.h"
#include "Camera.h"
#include "CubeMesh.h"
#include "PlaneMesh.h"

struct GLFWwindow;

class Renderer
{
public:

    bool Initialize();

    void Begin();

    void DrawCube();

    void ProcessInput(GLFWwindow* window, float deltaTime);

    void End();

    void Shutdown();

private:

    Shader shader;

    Camera camera;

    CubeMesh cubeMesh;

    PlaneMesh floorMesh;
};
