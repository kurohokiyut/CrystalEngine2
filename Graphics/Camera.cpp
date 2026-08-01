#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
    : m_Position(0.0f, 1.0f, 2.5f)
    , m_Front(0.0f, 0.0f, -1.0f)
    , m_WorldUp(0.0f, 1.0f, 0.0f)
    , m_MovementSpeed(3.0f)
{
}

Camera::~Camera()
{
}

void Camera::Initialize(
    float width,
    float height)
{
    m_Up = m_WorldUp;
    m_Front = glm::normalize(glm::vec3(0.0f, 0.5f, -0.5f));
    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));

    m_View = glm::lookAt(
        m_Position,
        m_Position + m_Front,
        m_Up);

    m_Projection = glm::perspective(
        glm::radians(45.0f),
        width / height,
        0.1f,
        100.0f);
}

void Camera::Update()
{
    m_View = glm::lookAt(
        m_Position,
        m_Position + m_Front,
        m_Up);
}

void Camera::ProcessKeyboard(GLFWwindow* window, float deltaTime)
{
    float velocity = m_MovementSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        m_Position += m_Front * velocity;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        m_Position -= m_Front * velocity;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        m_Position -= m_Right * velocity;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        m_Position += m_Right * velocity;

    Update();
}

glm::mat4 Camera::GetViewMatrix() const
{
    return m_View;
}

glm::mat4 Camera::GetProjectionMatrix() const
{
    return m_Projection;
}

glm::vec3& Camera::Position()
{
    return m_Position;
}

void Camera::UpdateCameraVectors()
{
    m_Front = glm::normalize(m_Front);
    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}
