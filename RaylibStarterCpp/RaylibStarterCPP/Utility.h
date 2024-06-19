#pragma once
#include "Matrix3.h"
#include "Vector3.h"

struct Plane {
    Plane(const MathClasses::Vector3 p1, const MathClasses::Vector3 p2);
    Plane() { N = Vector3(0, 0, 0); d = 0; }
    Plane(float x, float y, float d) : N(x, y, 0), d(d) {}
    Plane(const Vector3& n, float d) : N(n), d(d) {}

    MathClasses::Vector3 N;
    float d;

    // more to go here...
};
Plane::Plane(const MathClasses::Vector3 p1, const MathClasses::Vector3 p2)
{
    // calculate normalised vector from p0 to p1
    auto v = p2 - p1;
    v.Normalise();

    // set normal perpendicular to the vector
    N.x = -v.y;
    N.y = v.x;

    // calculate d
    d = -p1.Dot(N);
}

enum ePlaneResult : int {
    FRONT = 1,
    BACK = -1,
    INTERSECTS = 0
};