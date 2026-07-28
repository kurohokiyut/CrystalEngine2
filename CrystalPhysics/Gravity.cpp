#include "Gravity.h"
#include "RigidBody.h"

void Gravity::Apply(
    RigidBody& body,
    float deltaTime,
    float gravity)
{
    // Ignore static objects
    if (body.IsStatic)
        return;

    // Ignore objects that don't use gravity
    if (!body.UseGravity)
        return;

    // Don't keep accelerating downward if already on the ground
    if (body.IsGrounded)
        return;

    // Apply gravity to the Y velocity
    body.Velocity.y += gravity * deltaTime;
}