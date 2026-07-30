#include "DebugRenderer.h"

#include <iostream>

DebugRenderer::DebugRenderer()
{
}

DebugRenderer::~DebugRenderer()
{
}

bool DebugRenderer::Initialize()
{
    std::cout << "[Debug] DebugRenderer Initialized\n";

    return true;
}

void DebugRenderer::Begin()
{

}

void DebugRenderer::End()
{

}

void DebugRenderer::Shutdown()
{
    std::cout << "[Debug] DebugRenderer Shutdown\n";
}