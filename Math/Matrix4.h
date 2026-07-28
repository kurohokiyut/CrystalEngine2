#pragma once

class Vector3;

class Matrix4
{
public:

    float m[16];

    Matrix4();

    static Matrix4 Identity();

    static Matrix4 Perspective(
        float fov,
        float aspect,
        float nearPlane,
        float farPlane);

    static Matrix4 LookAt(
        const Vector3& eye,
        const Vector3& target,
        const Vector3& up);

    Matrix4 operator*(
        const Matrix4& other) const;
};