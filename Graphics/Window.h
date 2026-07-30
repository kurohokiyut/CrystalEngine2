#pragma once

#include <string>

struct GLFWwindow;

class Window
{
public:

    Window();
    ~Window();

    bool Create(
        int width,
        int height,
        const std::string& title
    );

    void PollEvents();

    void SwapBuffers();

    bool ShouldClose() const;

    void Destroy();

    GLFWwindow* GetNativeWindow() const;

private:

    GLFWwindow* m_Window;

    int m_Width;
    int m_Height;

    std::string m_Title;
};