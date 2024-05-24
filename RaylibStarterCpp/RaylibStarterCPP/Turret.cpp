#include "Turret.h"

#include "iostream"
#include "SpriteObject.h"

void Turret::OnUpdate(float deltaTime)
{
	float spin = 0.0f;

    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_Q))
    {
        spin -= 3.0f;
    }
    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_E))
    {
        spin += 3.0f;
    }

    Rotate(spin * deltaTime);
    std::cout << spin << std::endl;

    if (raylib::IsKeyPressed(raylib::KeyboardKey::KEY_SPACE))
    {
        
    }
}

