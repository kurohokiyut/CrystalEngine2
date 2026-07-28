//======================================================
// CrystalEngine
// Window.cpp
//======================================================

#include "Window.h"

#include <iostream>

#include <glad/glad.h>

Window::Window()
{
    m_Window = nullptr;
    m_Width = 0;
    m_Height = 0;
}

Window::~Window()
{
    Shutdown();
}

bool Window::Create(
    int width,
    int height,
    const std::string& title)
{
    m_Width = width;
    m_Height = height;

    //------------------------------------
    // GLFW
    //------------------------------------

    if (!glfwInit())
    {
        std::cout
            << "[Window] GLFW Initialization Failed"
            << std::endl;

        return false;
    }

    //------------------------------------
    // OpenGL Version
    //------------------------------------

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__

    glfwWindowHint(
        GLFW_OPENGL_FORWARD_COMPAT,
        GL_TRUE);

#endif

    //------------------------------------
    // Window
    //------------------------------------

    m_Window = glfwCreateWindow(
        width,
        height,
        title.c_str(),
        nullptr,
        nullptr);

    if (m_Window == nullptr)
    {
        std::cout
            << "[Window] Failed to Create Window"
            << std::endl;

        glfwTerminate();

        return false;
    }

    glfwMakeContextCurrent(m_Window);

    //------------------------------------
    // VSYNC
    //------------------------------------

    glfwSwapInterval(1);

    //------------------------------------
    // GLAD
    //------------------------------------

    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout
            << "[Window] Failed to Initialize GLAD"
            << std::endl;

        return false;
    }

    //------------------------------------
    // Viewport
    //------------------------------------

    glViewport(
        0,
        0,
        width,
        height);

    //------------------------------------
    // Resize Callback
    //------------------------------------

    glfwSetFramebufferSizeCallback(

        m_Window,

        [](GLFWwindow*, int w, int h)
        {
            glViewport(0, 0, w, h);
        }

    );

    std::cout
        << "[Window] Successfully Created"
        << std::endl;

    std::cout
        << "OpenGL Version : "
        << glGetString(GL_VERSION)
        << std::endl;

    return true;
}

void Window::Update()
{
    glfwSwapBuffers(m_Window);

    glfwPollEvents();
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(m_Window);
}

GLFWwindow* Window::GetNativeWindow() const
{
    return m_Window;
}

void Window::Shutdown()
{
    if (m_Window != nullptr)
    {
        glfwDestroyWindow(m_Window);

        m_Window = nullptr;
    }

    glfwTerminate();
}