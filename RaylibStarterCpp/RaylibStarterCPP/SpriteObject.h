#pragma once

#include "raylib_cpp.h"    // for raylib::Texture2D

#include "Colour.h"          // for Color
#include "GameObject.h"     // for GameObject

class SpriteObject : public GameObject
{
public:
    raylib::Texture2D* Sprite;
    MathClasses::Vector3 Origin;

    raylib::Color Tint;

    SpriteObject();
protected:
    void OnDraw() override;
};

