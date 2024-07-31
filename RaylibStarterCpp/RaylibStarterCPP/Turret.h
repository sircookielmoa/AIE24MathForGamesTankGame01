#pragma once

#include "TankPlayer.h"


class Turret : public SpriteObject
{
protected:
	void OnUpdate(float deltaTime) override;
};

