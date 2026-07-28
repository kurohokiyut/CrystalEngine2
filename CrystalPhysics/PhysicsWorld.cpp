#include "PhysicsWorld.h"

#include <algorithm>

#include "Gravity.h"

PhysicsWorld::PhysicsWorld()
{
    // 地球の重力
    WorldGravity = Vector3(0.0f, -9.81f, 0.0f);
}

void PhysicsWorld::AddBody(RigidBody* body)
{
    Bodies.push_back(body);
}

void PhysicsWorld::RemoveBody(RigidBody* body)
{
    Bodies.erase(
        std::remove(Bodies.begin(), Bodies.end(), body),
        Bodies.end()
    );
}

void PhysicsWorld::Update(float deltaTime)
{
    for (RigidBody* body : Bodies)
    {
        if (body == nullptr)
            continue;

        // 重力を適用
        Gravity::Apply(
            *body,
            deltaTime,
            WorldGravity.y
        );

        // Rigidbody更新
        body->Update(deltaTime);
    }
}