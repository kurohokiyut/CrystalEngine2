#pragma once

#include <vector>

#include "RigidBody.h"

class PhysicsWorld
{
public:

    PhysicsWorld();

    // 世界の重力
    Vector3 WorldGravity;

    // 登録されている物体
    std::vector<RigidBody*> Bodies;

    // オブジェクト登録
    void AddBody(RigidBody* body);

    // オブジェクト削除
    void RemoveBody(RigidBody* body);

    // 毎フレーム更新
    void Update(float deltaTime);
};