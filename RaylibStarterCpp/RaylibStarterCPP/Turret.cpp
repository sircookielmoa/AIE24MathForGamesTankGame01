#include "Turret.h"

#include "iostream"
#include "SpriteObject.h"

const float SPINSPEED = 4.0f;

void Turret::OnUpdate(float deltaTime)
{
	float spin = 0.0f;

    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_Q))
    {
        spin -= SPINSPEED;
    }
    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_E))
    {
        spin += SPINSPEED;
    }

    Rotate(spin * deltaTime);
    std::cout << spin << std::endl;

}

