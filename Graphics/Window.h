#pragma once

#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:

    Window();
    ~Window();

    bool Create(int width,
                int height,
                const std::string& title);

    void Update();

    void Shutdown();

    bool ShouldClose() const;

    GLFWwindow* GetNativeWindow() const;

private:

    GLFWwindow* m_Window;

    int m_Width;
    int m_Height;
};