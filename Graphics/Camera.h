#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:

    Camera();

    ~Camera();

    void Initialize(
        float width,
        float height
    );

    void Update();

    void ProcessKeyboard(GLFWwindow* window, float deltaTime);

    glm::mat4 GetViewMatrix() const;

    glm::mat4 GetProjectionMatrix() const;

    glm::vec3& Position();

private:

    void UpdateCameraVectors();

    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;

    float m_MovementSpeed;

    glm::mat4 m_View;
    glm::mat4 m_Projection;
};
