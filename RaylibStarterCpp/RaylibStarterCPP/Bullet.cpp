#include "Bullet.h"
#include "Vector3.h"
#include "Matrix3.h"

void Bullet::OnUpdate(float deltaTime)
{
	float bulletVelocity = 400.0f;

	//stupid
	Translate(GetForward() * (bulletVelocity * deltaTime));
}
