#pragma once

class Engine
{
public:

    Engine();

    ~Engine();

    bool Initialize();

    void Update(float deltaTime);

    void Shutdown();

    bool IsRunning() const;

private:

    bool m_Running;
};