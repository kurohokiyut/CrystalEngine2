#pragma once

class DebugRenderer
{
public:

    DebugRenderer();

    ~DebugRenderer();

    bool Initialize();

    void Begin();

    void End();

    void Shutdown();

};