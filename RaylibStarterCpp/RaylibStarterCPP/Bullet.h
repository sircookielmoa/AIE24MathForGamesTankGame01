#pragma once

#include "SpriteObject.h"
#include "CircleCollision.h"

class Bullet : public SpriteObject
{
public:
	~Bullet();

	CircleCollision* collisionObject;
	bool remove = false;


protected:
	void OnUpdate(float deltaTime) override;
};

