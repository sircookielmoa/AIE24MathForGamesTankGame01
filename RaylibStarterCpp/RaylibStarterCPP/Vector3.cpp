#include "Vector3.h"
namespace MathClasses
{
	MathClasses::Vector3::Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	MathClasses::Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	std::string MathClasses::Vector3::ToString() const
	{
		return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	}

	float MathClasses::Vector3::Magnitude() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float Vector3::SqrMagnitude() const
	{
		return Dot(*this);
	}

	float MathClasses::Vector3::Dot(Vector3 o) const
	{
		return x * o.x + y * o.y + z * o.z;
	}

	Vector3 MathClasses::Vector3::Normalised() const
	{
		Vector3 copy = *this;
		copy.Normalise();

		return copy;
	}

	void MathClasses::Vector3::Normalise()
	{
		float m = Magnitude();
		if (m != 0)
		{
			x /= m;
			y /= m;
			z /= m;
		}
		else
		{
			x = 0;
			y = 0;
			z = 0;
		}
	}

	Vector3 MathClasses::Vector3::Cross(Vector3 o) const
	{
		return Vector3(y * o.z - z * o.y,
			z * o.x - x * o.z,
			x * o.y - y * o.x);
	}

	float Vector3::AngleFrom2D()
	{
		return atan2f(y, x);
	}

	float Vector3::operator[](int index)
	{
		switch (index) {

		default:
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;


		}
	}

	Vector3 MathClasses::operator+(Vector3 a, Vector3 b)
	{
		return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	Vector3 MathClasses::operator-(Vector3 a, Vector3 b)
	{
		return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	Vector3 MathClasses::operator*(Vector3 a, float b)
	{
		return Vector3(a.x * b, a.y * b, a.z * b);
	}

	Vector3 MathClasses::operator*(float a, Vector3 b)
	{
		return b * a;
	}

	Vector3 operator*(Vector3 a, Vector3 b)
	{
		return Vector3(a.x * b.x, a.y * b.y, a.z *b.z);
	}

	bool MathClasses::operator==(Vector3 a, Vector3 b)
	{
		//if a[i] - b[i] <= .00001 then theyre probbaly meant to be the same
		for (int i = 0; i < 3; i++) {
			if (abs(a[i] - b[i]) <= .0001) {
				continue;
			}
			else {
				return false;
			}

		}
		return true;
	}

	bool MathClasses::operator!=(Vector3 a, Vector3 b)
	{
		return !(a == b);
	}
}