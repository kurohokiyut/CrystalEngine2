#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Initialize(
    float width,
    float height)
{
    m_Position =
        glm::vec3(
            0.0f,
            0.0f,
            3.0f);

    m_Target =
        glm::vec3(
            0.0f,
            0.0f,
            0.0f);

    m_Up =
        glm::vec3(
            0.0f,
            1.0f,
            0.0f);

    m_View =
        glm::lookAt(
            m_Position,
            m_Target,
            m_Up);

    m_Projection =
        glm::perspective(

            glm::radians(45.0f),

            width / height,

            0.1f,

            100.0f
        );
}

void Camera::Update()
{
    m_View =
        glm::lookAt(
            m_Position,
            m_Target,
            m_Up);
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