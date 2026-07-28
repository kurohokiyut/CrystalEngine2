//======================================================
// CrystalEngine
// Matrix4.cpp
//======================================================

#include "Matrix4.h"
#include "Vector3.h"

#include <cmath>

Matrix4::Matrix4()
{
    for (int i = 0; i < 16; i++)
        m[i] = 0.0f;
}

Matrix4 Matrix4::Identity()
{
    Matrix4 mat;

    mat.m[0] = 1.0f;
    mat.m[5] = 1.0f;
    mat.m[10] = 1.0f;
    mat.m[15] = 1.0f;

    return mat;
}

Matrix4 Matrix4::Perspective(
    float fov,
    float aspect,
    float nearPlane,
    float farPlane)
{
    Matrix4 mat;

    float tanHalf =
        tanf(fov * 0.5f);

    mat.m[0] =
        1.0f /
        (aspect * tanHalf);

    mat.m[5] =
        1.0f /
        tanHalf;

    mat.m[10] =
        -(farPlane + nearPlane) /
        (farPlane - nearPlane);

    mat.m[11] = -1.0f;

    mat.m[14] =
        -(2.0f * farPlane * nearPlane) /
        (farPlane - nearPlane);

    return mat;
}

Matrix4 Matrix4::LookAt(
    const Vector3& eye,
    const Vector3& target,
    const Vector3& up)
{
    Vector3 forward =
        (target - eye).Normalize();

    Vector3 right =
        forward.Cross(up).Normalize();

    Vector3 newUp =
        right.Cross(forward);

    Matrix4 view =
        Identity();

    view.m[0] = right.x;
    view.m[4] = right.y;
    view.m[8] = right.z;

    view.m[1] = newUp.x;
    view.m[5] = newUp.y;
    view.m[9] = newUp.z;

    view.m[2] = -forward.x;
    view.m[6] = -forward.y;
    view.m[10] = -forward.z;

    view.m[12] = -right.Dot(eye);
    view.m[13] = -newUp.Dot(eye);
    view.m[14] = forward.Dot(eye);

    return view;
}

Matrix4 Matrix4::operator*(
    const Matrix4& other) const
{
    Matrix4 result;

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            result.m[row * 4 + col] =

                m[row * 4 + 0] *
                other.m[col + 0]

                +

                m[row * 4 + 1] *
                other.m[col + 4]

                +

                m[row * 4 + 2] *
                other.m[col + 8]

                +

                m[row * 4 + 3] *
                other.m[col + 12];
        }
    }

    return result;
}