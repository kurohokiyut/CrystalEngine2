#include "Collision.h"

#include <cmath>

bool Collision::CheckAABB(
    const RigidBody& bodyA,
    const Collider& colliderA,
    const RigidBody& bodyB,
    const Collider& colliderB)
{
    if (!colliderA.Enabled || !colliderB.Enabled)
        return false;

    Vector3 minA = bodyA.Position + colliderA.Center - (colliderA.Size * 0.5f);
    Vector3 maxA = bodyA.Position + colliderA.Center + (colliderA.Size * 0.5f);

    Vector3 minB = bodyB.Position + colliderB.Center - (colliderB.Size * 0.5f);
    Vector3 maxB = bodyB.Position + colliderB.Center + (colliderB.Size * 0.5f);

    return
        minA.x <= maxB.x &&
        maxA.x >= minB.x &&

        minA.y <= maxB.y &&
        maxA.y >= minB.y &&

        minA.z <= maxB.z &&
        maxA.z >= minB.z;
}

void Collision::ResolveCollision(
    RigidBody& bodyA,
    const Collider& colliderA,
    RigidBody& bodyB,
    const Collider& colliderB)
{
    if (!CheckAABB(bodyA, colliderA, bodyB, colliderB))
        return;

    // このバージョンでは非常にシンプルな解決方法

    if (!bodyA.IsStatic)
    {
        bodyA.Velocity = Vector3::Zero();

        bodyA.IsGrounded = true;
    }

    if (!bodyB.IsStatic)
    {
        bodyB.Velocity = Vector3::Zero();

        bodyB.IsGrounded = true;
    }
}