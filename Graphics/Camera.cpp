//======================================================
// CrystalEngine
// Camera.cpp
//======================================================

#include "Camera.h"

Camera::Camera()
{
    // カメラ位置
    m_Position = Vector3(0.0f, 0.0f, 3.0f);

    // 原点を見る
    m_Target = Vector3(0.0f, 0.0f, 0.0f);

    Update();
}

Camera::~Camera()
{
}

void Camera::SetPosition(const Vector3& position)
{
    m_Position = position;

    Update();
}

void Camera::SetTarget(const Vector3& target)
{
    m_Target = target;

    Update();
}

void Camera::Update()
{
    // View行列を作成
    m_View = Matrix4::LookAt(
        m_Position,
        m_Target,
        Vector3(0.0f, 1.0f, 0.0f));
}

const Matrix4& Camera::GetViewMatrix() const
{
    return m_View;
}