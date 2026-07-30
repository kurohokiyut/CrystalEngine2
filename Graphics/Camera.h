#pragma once

#include <glm/glm.hpp>

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

    glm::mat4 GetViewMatrix() const;

    glm::mat4 GetProjectionMatrix() const;

    glm::vec3& Position();

private:

    glm::vec3 m_Position;
    glm::vec3 m_Target;
    glm::vec3 m_Up;

    glm::mat4 m_View;
    glm::mat4 m_Projection;
};