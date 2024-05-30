#include "TankPlayer.h"

#include <iostream>

void TankPlayer::OnUpdate(float deltaTime)
{
    const float MOVESPEED = 450.0f;
    const float SPINSPEED = 4.0f;

    //
    // check for key input 
    //
    float yMove = 0.0f;
    float spin = 0.0f;

    // W-S for UP-DOWN movement
    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_W))
    {
        yMove += MOVESPEED;
    }
    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_S))
    {
        yMove -= MOVESPEED;
    }

    // A-D for rotating movement
    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_A))
    {
        spin -= SPINSPEED;
    }
    if (raylib::IsKeyDown(raylib::KeyboardKey::KEY_D))
    {
        spin += SPINSPEED;
    }


    // total displacement for this frame
    Rotate(spin * deltaTime);
    MathClasses::Vector3 finalMove = GetForward() * (yMove * deltaTime);

    Translate(finalMove);
}
