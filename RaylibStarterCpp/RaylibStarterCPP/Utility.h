#pragma once
#include "Matrix3.h"
#include "Vector3.h"

struct Plane {
    Plane(const MathClasses::Vector3 p1, const MathClasses::Vector3 p2);
    Plane();
    Plane(const float x, const float y, const float d) : N(x, y, 0), d(d) {}
    Plane(const Vector3& n, const float d) : N(n), d(d) {}

    MathClasses::Vector3 N;
    float d;

    // more to go here...
};

enum e_plane_result : int {
    front = 1,
    back = -1,
    intersects = 0
};