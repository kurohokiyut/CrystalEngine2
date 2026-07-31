#include <iostream>

#include "Graphics/Window.h"
#include "Graphics/Renderer.h"

int main()
{
    Window window;

    if (!window.Create(1280, 720, "CrystalEngine v0.0.1"))
    {
        std::cout << "Failed to create window." << std::endl;
        return -1;
    }


    Renderer renderer;

    if (!renderer.Initialize())
    {
        std::cout << "Failed to initialize renderer." << std::endl;
        return -1;
    }


    while (!window.ShouldClose())
    {
        window.PollEvents();


        renderer.Begin();

        renderer.DrawCube();

        renderer.End();


        window.SwapBuffers();
    }


    renderer.Shutdown();

    window.Destroy();


    return 0;
}