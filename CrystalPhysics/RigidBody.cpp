#include "RigidBody.h"

RigidBody::RigidBody()
{
    Position = Vector3::Zero();
    Rotation = Vector3::Zero();
    Scale = Vector3::One();

    Velocity = Vector3::Zero();
    Acceleration = Vector3::Zero();

    Mass = 1.0f;
    Drag = 0.0f;

    UseGravity = true;
    IsStatic = false;
    IsGrounded = false;
}

void RigidBody::AddForce(const Vector3& force)
{
    if (IsStatic)
        return;

    // Newton's Second Law
    // F = ma
    // a = F / m

    Acceleration += force / Mass;
}

void RigidBody::AddImpulse(const Vector3& impulse)
{
    if (IsStatic)
        return;

    Velocity += impulse / Mass;
}

void RigidBody::Update(float deltaTime)
{
    if (IsStatic)
        return;

    // Update velocity
    Velocity += Acceleration * deltaTime;

    // Simple drag
    Velocity *= (1.0f - Drag * deltaTime);

    // Update position
    Position += Velocity * deltaTime;

    // Reset acceleration every frame
    Acceleration = Vector3::Zero();
}

void RigidBody::Reset()
{
    Position = Vector3::Zero();
    Rotation = Vector3::Zero();

    Velocity = Vector3::Zero();
    Acceleration = Vector3::Zero();

    IsGrounded = false;
}