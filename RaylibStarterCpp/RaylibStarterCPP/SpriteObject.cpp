#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
    Sprite = nullptr;
    Origin = MathClasses::Vector3(0.5f, 0.5f, 0.5f);
    Tint = Color{ 255, 255, 255, 255 };
}

void SpriteObject::OnDraw()
{
    // extract transform data position
    MathClasses::Vector3 pos = GetWorldPosition();
    float rot = GetWorldRotation() * RAD2DEG;
    MathClasses::Vector3 scl = GetWorldScale();

    // draw sprite using raylib
    /*Sprite->Draw(
        raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
        raylib::Rectangle(pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y),
        raylib::Vector2(Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y),
        rot,
        raylib::Color(Tint.rgba));*/

    if (Sprite == nullptr) return;

    

    DrawTexturePro(
        *Sprite,
        { 0,0, (float)Sprite->width, (float)Sprite->height },
        { pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y },
        { Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y },
        rot,
        Tint
    );
}
