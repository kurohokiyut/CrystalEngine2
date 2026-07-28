#pragma once

#include <cmath>

class Vector3
{
public:
    float x;
    float y;
    float z;

    // Constructors
    Vector3();
    Vector3(float x, float y, float z);

    // Basic Operators
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;

    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(float scalar);

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    // Math
    float Length() const;
    float LengthSquared() const;

    void Normalize();
    Vector3 Normalized() const;

    float Dot(const Vector3& other) const;
    Vector3 Cross(const Vector3& other) const;

    static Vector3 Zero();
    static Vector3 One();

    static Vector3 Up();
    static Vector3 Down();

    static Vector3 Left();
    static Vector3 Right();

    static Vector3 Forward();
    static Vector3 Back();
};