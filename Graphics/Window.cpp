#include "Window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window()
{
    m_Window = nullptr;

    m_Width = 0;
    m_Height = 0;
}

Window::~Window()
{
    Destroy();
}

bool Window::Create(
    int width,
    int height,
    const std::string& title)
{
    m_Width = width;
    m_Height = height;
    m_Title = title;

    if (!glfwInit())
    {
        std::cout << "GLFW Init Failed\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        GLFW_OPENGL_CORE_PROFILE
    );

    m_Window = glfwCreateWindow(
        width,
        height,
        title.c_str(),
        nullptr,
        nullptr
    );

    if (m_Window == nullptr)
    {
        std::cout << "Window Create Failed\n";

        glfwTerminate();

        return false;
    }

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD Failed\n";

        return false;
    }

    glViewport(
        0,
        0,
        width,
        height
    );

    glfwSwapInterval(1);

    std::cout
        << "CrystalEngine Window Created"
        << std::endl;

    return true;
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(m_Window);
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(m_Window);
}

void Window::Destroy()
{
    if (m_Window != nullptr)
    {
        glfwDestroyWindow(m_Window);

        m_Window = nullptr;
    }

    glfwTerminate();
}

GLFWwindow* Window::GetNativeWindow() const
{
    return m_Window;
}