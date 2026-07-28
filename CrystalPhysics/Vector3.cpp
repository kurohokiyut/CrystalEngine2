#include "Vector3.h"

Vector3::Vector3()
    : x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

Vector3 Vector3::operator+(const Vector3& other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar) const
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(float scalar) const
{
    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3& Vector3::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
    return x == other.x &&
           y == other.y &&
           z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const
{
    return !(*this == other);
}

float Vector3::LengthSquared() const
{
    return x*x + y*y + z*z;
}

float Vector3::Length() const
{
    return std::sqrt(LengthSquared());
}

void Vector3::Normalize()
{
    float len = Length();

    if (len > 0.0f)
    {
        x /= len;
        y /= len;
        z /= len;
    }
}

Vector3 Vector3::Normalized() const
{
    Vector3 v(*this);
    v.Normalize();
    return v;
}

float Vector3::Dot(const Vector3& other) const
{
    return x*other.x +
           y*other.y +
           z*other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const
{
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector3 Vector3::Zero()
{
    return Vector3(0,0,0);
}

Vector3 Vector3::One()
{
    return Vector3(1,1,1);
}

Vector3 Vector3::Up()
{
    return Vector3(0,1,0);
}

Vector3 Vector3::Down()
{
    return Vector3(0,-1,0);
}

Vector3 Vector3::Left()
{
    return Vector3(-1,0,0);
}

Vector3 Vector3::Right()
{
    return Vector3(1,0,0);
}

Vector3 Vector3::Forward()
{
    return Vector3(0,0,1);
}

Vector3 Vector3::Back()
{
    return Vector3(0,0,-1);
}