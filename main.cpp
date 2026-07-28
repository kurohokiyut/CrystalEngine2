//======================================================
// CrystalEngine
// main.cpp
// CrystalEngine v0.0.1 Alpha
//======================================================

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Engine.h"
#include "Core/Timer.h"

#include "Graphics/Window.h"
#include "Graphics/Renderer.h"
#include "Graphics/Camera.h"

#include "CrystalPhysics/PhysicsWorld.h"

#include "Debug/DebugRenderer.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main()
{
    //--------------------------------------------------
    // GLFW
    //--------------------------------------------------

    if (!glfwInit())
    {
        std::cout << "GLFW Initialization Failed\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE,
                   GLFW_OPENGL_CORE_PROFILE);

    //--------------------------------------------------
    // Window
    //--------------------------------------------------

    GLFWwindow* window =
        glfwCreateWindow(
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            "CrystalEngine v0.0.1 Alpha",
            nullptr,
            nullptr);

    if (!window)
    {
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    //--------------------------------------------------
    // GLAD
    //--------------------------------------------------

    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD Initialization Failed\n";

        glfwTerminate();

        return -1;
    }

    //--------------------------------------------------
    // OpenGL Settings
    //--------------------------------------------------

    glViewport(
        0,
        0,
        WINDOW_WIDTH,
        WINDOW_HEIGHT);

    glEnable(GL_DEPTH_TEST);

    //--------------------------------------------------
    // Engine
    //--------------------------------------------------

    Engine engine;

    engine.Initialize();

    //--------------------------------------------------
    // Physics
    //--------------------------------------------------

    PhysicsWorld physics;

    //--------------------------------------------------
    // Camera
    //--------------------------------------------------

    Camera camera;

    //--------------------------------------------------
    // Renderer
    //--------------------------------------------------

    Renderer renderer;

    renderer.Initialize();

    //--------------------------------------------------
    // Debug
    //--------------------------------------------------

    DebugRenderer debug;

    //--------------------------------------------------
    // Timer
    //--------------------------------------------------

    Timer timer;

    //--------------------------------------------------
    // Main Loop
    //--------------------------------------------------

    while (!glfwWindowShouldClose(window))
    {
        //--------------------------------------------------
        // Time
        //--------------------------------------------------

        float deltaTime =
            timer.GetDeltaTime();

        //--------------------------------------------------
        // Input
        //--------------------------------------------------

        glfwPollEvents();

        //--------------------------------------------------
        // Physics
        //--------------------------------------------------

        physics.Update(deltaTime);

        //--------------------------------------------------
        // Rendering
        //--------------------------------------------------

        glClearColor(
            0.10f,
            0.12f,
            0.16f,
            1.0f);

        glClear(
            GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT);

        renderer.Begin();

        renderer.DrawCube();

        renderer.End();

        //--------------------------------------------------
        // Debug
        //--------------------------------------------------

        debug.Begin();

        debug.DrawText(
            "CrystalEngine v0.0.1 Alpha",
            10,
            10);

        debug.DrawFPS(
            timer.GetFPS());

        debug.End();

        //--------------------------------------------------
        // Present
        //--------------------------------------------------

        glfwSwapBuffers(window);
    }

    //--------------------------------------------------
    // Shutdown
    //--------------------------------------------------

    renderer.Shutdown();

    engine.Shutdown();

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}