//======================================================
// CrystalEngine
// Renderer.cpp
//======================================================

#include "Renderer.h"

#include <iostream>

#include <glad/glad.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::Initialize()
{
    std::cout << "[Renderer] Initializing...\n";

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    glCullFace(GL_BACK);

    glFrontFace(GL_CCW);

    std::cout << "[Renderer] Ready\n";

    return true;
}

void Renderer::Begin()
{
    glClearColor(
        0.10f,
        0.12f,
        0.16f,
        1.0f);

    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT);
}

void Renderer::DrawCube()
{
    //--------------------------------------------------
    // Temporary
    //--------------------------------------------------
    //
    // v0.0.1 Alphaでは
    // Cube描画はまだ実装しない。
    //
    // 次のバージョンで
    //
    // VAO
    // VBO
    // EBO
    // Shader
    //
    // を追加する。
    //
    //--------------------------------------------------
}

void Renderer::End()
{
    glFlush();
}

void Renderer::Shutdown()
{
    std::cout << "[Renderer] Shutdown\n";
}