#pragma once

#include "Vector3.h"

class RigidBody;

class Gravity
{
public:

    // Earth gravity (m/s²)
    static constexpr float DefaultGravity = -9.81f;

    static void Apply(
        RigidBody& body,
        float deltaTime,
        float gravity = DefaultGravity
    );
};