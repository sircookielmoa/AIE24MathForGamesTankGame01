#include "CircleCollision.h"
#include "PlaneCollision.h"

PlaneCollision::PlaneCollision()
{
}

PlaneCollision::PlaneCollision(float x, float y, float z, float s)
{
    normal.x = x;
    normal.y = y;
    normal.z = z;
    scalar = s;
}

PlaneCollision::PlaneCollision(const MathClasses::Vector3& _normal, float s)
{
    normal = _normal;
    scalar = s;
}

PlaneCollision::PlaneCollision(const MathClasses::Vector3& p1, const MathClasses::Vector3& p2)
{
    // calculate normalised vector from p0 to p1
    auto v = p2 - p1;
    v.Normalise();

    // set normal perpendicular to the vector
    normal.x = -v.y;
    normal.y = v.x;

    // calculate d
    scalar = -p1.Dot(normal);
}


float PlaneCollision::DistanceTo(const MathClasses::Vector3& p) const
{
    return p.Dot(normal) + scalar;
}

MathClasses::Vector3 PlaneCollision::ClosestPoint(const MathClasses::Vector3& p) const
{
    return p - normal * DistanceTo(p);
}

ePlaneResult PlaneCollision::testSide(const CircleCollision& circle) const
{
    float t = DistanceTo(circle.center);

    if( t > circle.radius)
    {
        return ePlaneResult::front;
    }
    else if(t < circle.radius)
    {
        return ePlaneResult::back;
    }
    return ePlaneResult::intersects;
}

ePlaneResult PlaneCollision::testSide(const MathClasses::Vector3& p) const
{
    float t = p.Dot(normal) + scalar;

    if (t < 0)
    {
        return ePlaneResult::back;
    }
    else if (t > 0)
    {
        return ePlaneResult::front;
    }
    return ePlaneResult::intersects;
}

void PlaneCollision::ShowGeo(MathClasses::Vector3& _normal, float s)
{
    Vector2 startPos{ _normal.x,_normal.y };
    Vector2 endPos{ 0,0 };
    DrawLineV(startPos, endPos, RED);
}


PlaneCollision::~PlaneCollision()
{
}