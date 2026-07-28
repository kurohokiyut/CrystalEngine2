cmake_minimum_required(VERSION 3.20)

project(CrystalEngine VERSION 0.0.1 LANGUAGES CXX)

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
# GLFW (Binary)
# ==========================================

set(GLFW_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/External/glfw/include
)

set(GLFW_LIBRARY
    ${CMAKE_SOURCE_DIR}/External/glfw/lib/glfw3.lib
)

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

    Math/Vector2.cpp
    Math/Vector3.cpp
    Math/Matrix4.cpp
    Math/Quaternion.cpp
    Math/Transform.cpp

    CrystalPhysics/RigidBody.cpp
    CrystalPhysics/Gravity.cpp
    CrystalPhysics/Collider.cpp
    CrystalPhysics/Collision.cpp
    CrystalPhysics/PhysicsWorld.cpp

    Debug/DebugRenderer.cpp
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

    ${GLFW_INCLUDE_DIR}

    External/glad/include

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

    ${GLFW_LIBRARY}

    OpenGL::GL
)

# ==========================================
# Copy glfw3.dll
# ==========================================

if(WIN32)

    add_custom_command(TARGET CrystalEngine POST_BUILD

        COMMAND ${CMAKE_COMMAND} -E copy_if_different

        ${CMAKE_SOURCE_DIR}/External/glfw/lib/glfw3.dll

        $<TARGET_FILE_DIR:CrystalEngine>

    )

endif()