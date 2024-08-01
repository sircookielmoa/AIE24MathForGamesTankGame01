#pragma once

#include "Raylib.h"    // for raylib::Texture2D

#include "Colour.h"          // for Color
#include "GameObject.h"     // for GameObject

class SpriteObject : public GameObject
{
public:
    Texture2D* Sprite;

	MathClasses::Vector3 Origin;

    Color Tint;

    SpriteObject();
protected:
    void OnDraw() override;
};

