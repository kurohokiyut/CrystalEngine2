#pragma once

#include "Vector3.h"

class RigidBody
{
public:

    // Position in world space
    Vector3 Position;

    // Rotation (Euler angles for now)
    Vector3 Rotation;

    // Scale
    Vector3 Scale;

    // Physics
    Vector3 Velocity;
    Vector3 Acceleration;

    // Physical properties
    float Mass;
    float Drag;

    bool UseGravity;
    bool IsStatic;
    bool IsGrounded;

public:

    RigidBody();

    void AddForce(const Vector3& force);

    void AddImpulse(const Vector3& impulse);

    void Update(float deltaTime);

    void Reset();
};