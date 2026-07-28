#pragma once

#include "Vector3.h"

enum class ColliderType
{
    None,
    Box,
    Sphere,
    Capsule
};

class Collider
{
public:

    ColliderType Type;

    // 中心座標（ローカル）
    Vector3 Center;

    // Boxサイズ
    Vector3 Size;

    // Sphere半径
    float Radius;

    // 有効かどうか
    bool Enabled;

public:

    Collider();

    virtual ~Collider();
};