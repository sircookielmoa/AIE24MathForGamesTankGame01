#pragma once

#include "GameObject.h"
#include "SpriteObject.h"

#include <iostream>

class Turret : public SpriteObject
{
protected:
	void OnUpdate(float deltaTime) override;
};

