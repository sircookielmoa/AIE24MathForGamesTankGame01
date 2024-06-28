#include "Utility.h"

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

Plane::Plane()
{
}