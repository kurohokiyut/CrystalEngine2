#pragma once

#include "../Math/Vector3.h"
#include "../Math/Matrix4.h"

class Camera
{
public:

    Camera();
    ~Camera();

    void SetPosition(const Vector3& position);

    void SetTarget(const Vector3& target);

    const Matrix4& GetViewMatrix() const;

    void Update();

private:

    Vector3 m_Position;
    Vector3 m_Target;

    Matrix4 m_View;
};