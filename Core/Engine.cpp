//======================================================
// CrystalEngine
// Engine.cpp
//======================================================

#include "Engine.h"

#include <iostream>

Engine::Engine()
{
    m_Running = false;
}

Engine::~Engine()
{
}

bool Engine::Initialize()
{
    std::cout << "=====================================\n";
    std::cout << " CrystalEngine v0.0.1 Alpha\n";
    std::cout << " Initializing Engine...\n";
    std::cout << "=====================================\n";

    m_Running = true;

    std::cout << "[OK] Engine Initialized\n";

    return true;
}

void Engine::Update(float deltaTime)
{
    if (!m_Running)
        return;

    // --------------------------------------------------
    // 将来ここに追加される予定
    //
    // Input
    // Physics
    // Audio
    // Animation
    // AI
    // Scene
    // Renderer
    // --------------------------------------------------
}

void Engine::Shutdown()
{
    if (!m_Running)
        return;

    std::cout << "[OK] Engine Shutdown\n";

    m_Running = false;
}

bool Engine::IsRunning() const
{
    return m_Running;
}