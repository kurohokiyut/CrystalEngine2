cmake_minimum_required(VERSION 3.20)

project(CrystalEngine VERSION 0.0.1 LANGUAGES C CXX)

# ==========================================
# C++17
# ==========================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==========================================
# OpenGL
# ==========================================

find_package(OpenGL REQUIRED)


# ==========================================
# GLFW
# ==========================================

add_subdirectory(External/glfw)


# ==========================================
# GLAD
# ==========================================

add_library(glad STATIC
    External/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    External/glad/include
)


# ==========================================
# Source Files
# ==========================================

set(SOURCES

    main.cpp

    Core/Engine.cpp
    Core/Timer.cpp

    Graphics/Window.cpp
    Graphics/Renderer.cpp
    Graphics/Shader.cpp
    Graphics/Camera.cpp
    Graphics/Mesh.cpp
    Graphics/CubeMesh.cpp
    Graphics/PlaneMesh.cpp
    Graphics/VertexArray.cpp
    Graphics/VertexBuffer.cpp
    Graphics/IndexBuffer.cpp

    Math/Matrix4.cpp

    CrystalPhysics/Vector3.cpp
    CrystalPhysics/RigidBody.cpp
    CrystalPhysics/Gravity.cpp
    CrystalPhysics/Collider.cpp
    CrystalPhysics/Collision.cpp
    CrystalPhysics/PhysicsWorld.cpp

    Debug/DebugRenderer.cpp
    Debug/DebugRenderer.h
    Debug/DebugText.cpp
    Debug/DebugText.h
)


# ==========================================
# Executable
# ==========================================

add_executable(CrystalEngine
    ${SOURCES}
)


# ==========================================
# Include Directories
# ==========================================

target_include_directories(CrystalEngine PRIVATE

    .

    External/glad/include
    External/glfw/include
    External/glm

    Core
    Graphics
    Math
    CrystalPhysics
    Debug
)


# ==========================================
# Link Libraries
# ==========================================

target_link_libraries(CrystalEngine PRIVATE

    glad
    glfw
    OpenGL::GL

)


# ==========================================
# Windows Settings
# ==========================================

if(WIN32)

    target_compile_definitions(CrystalEngine PRIVATE
        _CRT_SECURE_NO_WARNINGS
    )

endif()