#pragma once

#include "RigidBody.h"
#include "Collider.h"

class Collision
{
public:

    // AABB同士の衝突判定
    static bool CheckAABB(
        const RigidBody& bodyA,
        const Collider& colliderA,
        const RigidBody& bodyB,
        const Collider& colliderB);

    // 衝突を解決（簡易版）
    static void ResolveCollision(
        RigidBody& bodyA,
        const Collider& colliderA,
        RigidBody& bodyB,
        const Collider& colliderB);
};