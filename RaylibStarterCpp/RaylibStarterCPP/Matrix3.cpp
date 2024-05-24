#include "Matrix3.h"
#include "Vector3.h"
//hello

namespace MathClasses
{
	MathClasses::Matrix3::Matrix3()
	{
		m1 = m2 = m3 =
		m4 = m5 = m6 =
		m7 = m8 = m9 = 0.0f;
	}

	MathClasses::Matrix3::Matrix3(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
	{
		m1 = a1;
		m2 = a2;
		m3 = a3;
		m4 = a4;
		m5 = a5;
		m6 = a6;
		m7 = a7;
		m8 = a8;
		m9 = a9;
	}

	MathClasses::Matrix3::Matrix3(float* v)
	{
		m1 = v[0];
		m2 = v[1];
		m3 = v[2];
		m4 = v[3];
		m5 = v[4];
		m6 = v[5];
		m7 = v[6];
		m8 = v[7];
		m9 = v[8];
	}

	std::string MathClasses::Matrix3::ToString() const
	{
		return std::to_string(m1) + ", " + std::to_string(m2) + ", " + std::to_string(m3) + ", " + std::to_string(m4) + ", " + std::to_string(m5) + ", " + std::to_string(m6) + ", " + std::to_string(m7) + ", " + std::to_string(m8) + ", " + std::to_string(m9);
	}

	Matrix3 MathClasses::Matrix3::MakeIdentity()
	{
		Matrix3 identity;
		identity.m1 = 1;
		identity.m2 = 0;
		identity.m3 = 0;

		identity.m4 = 0;
		identity.m5 = 1;
		identity.m6 = 0;

		identity.m7 = 0;
		identity.m8 = 0;
		identity.m9 = 1;

		return identity;
	}

	Matrix3 MathClasses::Matrix3::MakeTranslation(float x, float y, float z)
	{
		return Matrix3(1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			x, y, z);
	}

	Matrix3 MathClasses::Matrix3::MakeTranslation(Vector3 v)
	{
		return MakeTranslation(v.x, v.y, v.z);
	}

	Matrix3 MathClasses::Matrix3::MakeRotateX(float a)
	{
		return Matrix3(
			1.0f, 0.0f, 0.0f,
			0.0f, cosf(a), -sinf(a),
			0.0f, sinf(a), cosf(a));
	}

	Matrix3 MathClasses::Matrix3::MakeRotateY(float a)
	{
		return Matrix3(
			cosf(a), 0.0f, sinf(a),
			0.0f, 1.0f, 0.0f,
			-sinf(a), 0.0f, cosf(a));
	}

	Matrix3 MathClasses::Matrix3::MakeRotateZ(float a)
	{
		return Matrix3(
			cosf(a), sinf(a), 0.0f,
			-sinf(a), cosf(a), 0.0f,
			0.0f, 0.0f, 1.0f);
	}

	Matrix3 MathClasses::Matrix3::MakeEuler(float pitch, float yaw, float roll)
	{
		Matrix3 x = MakeRotateX(pitch);
		Matrix3 y = MakeRotateY(yaw);
		Matrix3 z = MakeRotateZ(roll);

		// combine rotations in a specific order
		return (z * y * x);
	}

	Matrix3 MathClasses::Matrix3::MakeEuler(Vector3 e)
	{
		return MakeEuler(e.x, e.y, e.z);
	}

	Matrix3 MathClasses::Matrix3::MakeScale(float x, float y)
	{
		return Matrix3(
			x, 0.0f, 0.0f,
			0.0f, y, 0.0f,
			0.0f, 0.0f, 1.0f);
	}

	Matrix3 MathClasses::Matrix3::MakeScale(float x, float y, float z)
	{
		return Matrix3(
			x, 0.0f, 0.0f,
			0.0f, y, 0.0f,
			0.0f, 0.0f, z);
	}

	Matrix3 MathClasses::Matrix3::MakeScale(Vector3 s)
	{
		return MakeScale(s.x, s.y, s.z);
	}

	Matrix3 MathClasses::Matrix3::Transposed()
	{
		return Matrix3(
			m1, m4, m7, 
			m2, m5, m8, 
			m3, m6, m9);
	}

	float Matrix3::operator[](int index)
	{
		switch (index) {

		default:
		case 0:
			return m1;
			break;
		case 1:
			return m2;
			break;
		case 2:
			return m3;
			break;
		case 3:
			return m4;
			break;
		case 4:
			return m5;
			break;
		case 5:
			return m6;
			break;
		case 6:
			return m7;
			break;
		case 7:
			return m8;
			break;
		case 8:
			return m9;
			break;
		}

	}

	Matrix3 MathClasses::operator*(Matrix3 a, Matrix3 rhs)
	{
		return Matrix3(
			a.m1 * rhs.m1 + a.m4 * rhs.m2 + a.m7 * rhs.m3,
			a.m2 * rhs.m1 + a.m5 * rhs.m2 + a.m8 * rhs.m3,
			a.m3 * rhs.m1 + a.m6 * rhs.m2 + a.m9 * rhs.m3,

			a.m1 * rhs.m4 + a.m4 * rhs.m5 + a.m7 * rhs.m6,
			a.m2 * rhs.m4 + a.m5 * rhs.m5 + a.m8 * rhs.m6,
			a.m3 * rhs.m4 + a.m6 * rhs.m5 + a.m9 * rhs.m6,

			a.m1 * rhs.m7 + a.m4 * rhs.m8 + a.m7 * rhs.m9,
			a.m2 * rhs.m7 + a.m5 * rhs.m8 + a.m8 * rhs.m9,
			a.m3 * rhs.m7 + a.m6 * rhs.m8 + a.m9 * rhs.m9);
	}

	Vector3 MathClasses::operator*(Matrix3 a, Vector3 b)
	{
		return Vector3(
			Vector3(a.m1, a.m4, a.m7).Dot(b),
			Vector3(a.m2, a.m5, a.m8).Dot(b),
			Vector3(a.m3, a.m6, a.m9).Dot(b));
	}

	bool MathClasses::operator==(Matrix3 a, Matrix3 b)
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

	bool MathClasses::operator!=(Matrix3 a, Matrix3 b)
	{
		return !(a == b);
	}
}