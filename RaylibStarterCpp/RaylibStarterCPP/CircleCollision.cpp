#include "CircleCollision.h"
#include "PlaneCollision.h"

CircleCollision::CircleCollision(const MathClasses::Vector3& p, float r)
	:center(p), radius(r)
{
}

MathClasses::Vector3 CircleCollision::ClosestPoint(const MathClasses::Vector3& p) const
{
	MathClasses::Vector3 toPoint = p - center;

	if(toPoint.Magnitude() > radius * radius)
	{
		toPoint = toPoint.Normalised() * radius;
	}
	return center + toPoint;
}

void CircleCollision::ShowGeo(MathClasses::Vector3 _circlePos, float _radius)
{
	DrawCircleLines(_circlePos.x, _circlePos.y, _radius, GREEN);
}

bool CircleCollision::Overlaps(const MathClasses::Vector3* p) const
{
	MathClasses::Vector3 toPoint = center - *p;
	if(toPoint.Magnitude() <= (radius * radius))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CircleCollision::Overlaps(const CircleCollision* circleCo) const
{
	float displacement = (center - circleCo->center).Magnitude();
	return displacement <= radius + circleCo->radius;
}

bool CircleCollision::Overlaps(const PlaneCollision* planeCo) const
{
	auto displacement = planeCo->ClosestPoint(center) - center;
	return displacement.Dot(displacement) <= (radius * radius);
}
