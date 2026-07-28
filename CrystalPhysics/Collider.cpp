#include "Collider.h"

Collider::Collider()
{
    Type = ColliderType::Box;

    Center = Vector3::Zero();

    Size = Vector3::One();

    Radius = 0.5f;

    Enabled = true;
}

Collider::~Collider()
{
}