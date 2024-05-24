#pragma once
#include <string>

namespace MathClasses
{
    struct Vector3
    {
        float x, y, z;

        Vector3();
        Vector3(float x, float y, float z);

        std::string ToString() const;

        float Magnitude() const;
        float SqrMagnitude() const;
        float Dot(Vector3 o) const;
        Vector3 Normalised() const;
        void Normalise();
        Vector3 Cross(Vector3 o) const;
        float AngleFrom2D();

        friend Vector3 operator+(Vector3 a, Vector3 b);
        friend Vector3 operator-(Vector3 a, Vector3 b);
        friend Vector3 operator*(Vector3 a, float b);
        friend Vector3 operator*(float a, Vector3 b);
        friend Vector3 operator*(Vector3 a, Vector3 b);

        float operator[](int index);

        friend bool operator==(Vector3 a, Vector3 b);
        friend bool operator!=(Vector3 a, Vector3 b);
	};
}
using Vector3 = MathClasses::Vector3;