#pragma once
#include "GameObject.h"

class CircleCollision;


enum ePlaneResult : int {
    front = 1,
    back = -1,
    intersects = 0
};

class PlaneCollision : public GameObject
{
public:

	PlaneCollision();
	PlaneCollision(float x, float y, float z, float s);
	PlaneCollision(const MathClasses::Vector3& _normal, float s);
	PlaneCollision(const MathClasses::Vector3& p1, const MathClasses::Vector3& p2);
	~PlaneCollision();

	MathClasses::Vector3 normal;
	float scalar;



	float DistanceTo(const MathClasses::Vector3& p) const;
	MathClasses::Vector3 ClosestPoint(const MathClasses::Vector3& p) const;

	void ShowGeo(MathClasses::Vector3& _normal, float s);

	ePlaneResult testSide(const MathClasses::Vector3& p) const; //Points
	ePlaneResult testSide(const CircleCollision& circle) const; // Circles

};