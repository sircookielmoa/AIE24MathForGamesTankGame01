#pragma once

#include "TankPlayer.h"
#include "Turret.h"
#include "Bullet.h"
#include "PlaneCollision.h"

#include <vector>

class Game
{
public:

	~Game();

	void Initialization();
	void Update();
	void Draw();

private:

	TankPlayer* player;
	Turret* turret;
	CircleCollision* barrel;

	Texture2D tankSprite;
	Texture2D tankTurretSprite;
	Texture2D tankBullet;
	Texture2D barrelSprite;


	std::vector<PlaneCollision> awesomeBorder{};
	std::vector<CircleCollision*> entities{};

	std::vector<Bullet*> bulletsInWorld{};
	std::vector<Bullet*> bulletsToRemove{};

};
