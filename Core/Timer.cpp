#include "Timer.h"

#include <GLFW/glfw3.h>

Timer::Timer()
{
    m_LastTime = glfwGetTime();
    m_CurrentTime = m_LastTime;
    m_DeltaTime = 0.0f;
}

void Timer::Update()
{
    m_CurrentTime = glfwGetTime();

    m_DeltaTime =
        static_cast<float>(m_CurrentTime - m_LastTime);

    m_LastTime = m_CurrentTime;
}

float Timer::GetDeltaTime() const
{
    return m_DeltaTime;
}

float Timer::GetTime() const
{
    return static_cast<float>(m_CurrentTime);
}