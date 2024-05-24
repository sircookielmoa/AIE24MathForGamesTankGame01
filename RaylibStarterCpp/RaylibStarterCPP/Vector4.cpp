#include "Vector4.h"

namespace MathClasses
{
	MathClasses::Vector4::Vector4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	MathClasses::Vector4::Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	std::string MathClasses::Vector4::ToString() const
	{
		return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
	}

	float MathClasses::Vector4::Magnitude() const
	{
		return sqrtf(x * x + y * y + z * z + w * w);
	}

	float Vector4::SqrMagnitude() const
	{
		return Dot(*this);
	}

	float MathClasses::Vector4::Dot(Vector4 o) const
	{
		return x * o.x + y * o.y + z * o.z + w * o.w;
	}

	Vector4 MathClasses::Vector4::Normalised() const
	{
		Vector4 copy = *this;
		copy.Normalise();

		return copy;
	}

	void MathClasses::Vector4::Normalise()
	{
		float m = Magnitude();
		if (m != 0)
		{
			x /= m;
			y /= m;
			z /= m;
			w /= m;
		}
		else
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
	}

	Vector4 MathClasses::Vector4::Cross(Vector4 o) const
	{
		return Vector4(y * o.z - z * o.y,
			z * o.x - x * o.z,
			x * o.y - y * o.x,
			0);
	}

	float Vector4::operator[](int index)
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
		case 3:
			return w;
			break;


		}
	}

	Vector4 MathClasses::operator+(Vector4 a, Vector4 b)
	{
		return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	}

	Vector4 MathClasses::operator-(Vector4 a, Vector4 b)
	{
		return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	}

	Vector4 MathClasses::operator*(Vector4 a, float b)
	{
		return Vector4(a.x * b, a.y * b, a.z * b, a.w * b);
	}

	Vector4 MathClasses::operator*(float a, Vector4 b)
	{
		return b * a;
	}

	bool MathClasses::operator==(Vector4 a, Vector4 b)
	{
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

	bool MathClasses::operator!=(Vector4 a, Vector4 b)
	{
		return !(a == b);
	}
}