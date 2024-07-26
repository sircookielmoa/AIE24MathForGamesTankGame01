#pragma once

#include "SpriteObject.h"
#include <cmath>


class PlaneCollision;

class CircleCollision : public SpriteObject
{
public:

	~CircleCollision() {};

	CircleCollision() {};
	CircleCollision(const MathClasses::Vector3& p, float r);

	MathClasses::Vector3 center;
	float radius;

	MathClasses::Vector3 Minimum;
	MathClasses::Vector3 Maximum;

	void Fit(const MathClasses::Vector3* points, unsigned int count);
	
	MathClasses::Vector3 ClosestPoint(const MathClasses::Vector3& p) const;

	void ShowGeo(MathClasses::Vector3 _circlePos, float _radius);

	bool Overlaps(const MathClasses::Vector3* p) const;
	bool Overlaps(const CircleCollision* circleCo) const;
	bool Overlaps(const PlaneCollision* planeCo) const;

};

