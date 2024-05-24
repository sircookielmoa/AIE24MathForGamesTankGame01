#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

namespace MathClasses
{
	MathClasses::Matrix4::Matrix4()
	{
		m1 = m2 = m3 = m4 =
			m5 = m6 = m7 = m8 =
			m9 = m10 = m11 = m12 =
			m13 = m14 = m15 = m16 = 0.0f;
	}

	MathClasses::Matrix4::Matrix4(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16)
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
		m10 = a10;
		m11 = a11;
		m12 = a12;
		m13 = a13;
		m14 = a14;
		m15 = a15;
		m16 = a16;
	}

	MathClasses::Matrix4::Matrix4(float* v)
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
		m10 = v[9];
		m11 = v[10];
		m12 = v[11];
		m13 = v[12];
		m14 = v[13];
		m15 = v[14];
		m16 = v[15];

	}

	std::string MathClasses::Matrix4::ToString() const
	{
		return std::to_string(m1) + ", " + std::to_string(m2) + ", " + std::to_string(m3) + ", " + std::to_string(m4) + ", " + std::to_string(m5) + ", " + std::to_string(m6) + ", " + std::to_string(m7) + ", " + std::to_string(m8) + ", " + std::to_string(m9) + ", " + std::to_string(m10) + ", " + std::to_string(m11) + ", " + std::to_string(m12) + ", " + std::to_string(m13) + ", " + std::to_string(m14) + ", " + std::to_string(m15) + ", " + std::to_string(m16) + ", ";
	}

	Matrix4 MathClasses::Matrix4::MakeIdentity()
	{
		Matrix4 identity;
		identity.m1 = 1;
		identity.m2 = 0;
		identity.m3 = 0;
		identity.m4 = 0;

		identity.m5 = 0;
		identity.m6 = 1;
		identity.m7 = 0;
		identity.m8 = 0;

		identity.m9 = 0;
		identity.m10 = 0;
		identity.m11 = 1;
		identity.m12 = 0;

		identity.m13 = 0;
		identity.m14 = 0;
		identity.m15 = 0;
		identity.m16 = 1;


		return identity;
	}

	Matrix4 MathClasses::Matrix4::MakeTranslation(float x, float y, float z)
	{
		return Matrix4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			x, y, z, 1.0f);
	}

	Matrix4 MathClasses::Matrix4::MakeTranslation(Vector3 v)
	{
		return MakeTranslation(v.x, v.y, v.z);
	}

	Matrix4 MathClasses::Matrix4::MakeRotateX(float a)
	{
		return Matrix4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, cosf(a), -sinf(a), 0.0f,
			0.0f, sinf(a), cosf(a), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}

	Matrix4 MathClasses::Matrix4::MakeRotateY(float a)
	{
		return Matrix4(
			cosf(a), 0.0f, sinf(a), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			-sinf(a), 0.0f, cosf(a), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

	}

	Matrix4 MathClasses::Matrix4::MakeRotateZ(float a)
	{
		return Matrix4(
			cosf(a), sinf(a), 0.0f, 0.0f,
			-sinf(a), cosf(a), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}

	Matrix4 MathClasses::Matrix4::MakeEuler(float pitch, float yaw, float roll)
	{
		Matrix4 x = MakeRotateX(pitch);
		Matrix4 y = MakeRotateY(yaw);
		Matrix4 z = MakeRotateZ(roll);

		return (z * y * x);
	}

	Matrix4 MathClasses::Matrix4::MakeEuler(Vector3 e)
	{
		return MakeEuler(e.x, e.y, e.z);
	}

	Matrix4 MathClasses::Matrix4::MakeScale(float x, float y)
	{
		return Matrix4(
			x, 0.0f, 0.0f, 0.0f,
			0.0f, y, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}

	Matrix4 MathClasses::Matrix4::MakeScale(float x, float y, float z)
	{
		return Matrix4(
			x, 0.0f, 0.0f, 0.0f,
			0.0f, y, 0.0f, 0.0f,
			0.0f, 0.0f, z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}

	Matrix4 MathClasses::Matrix4::MakeScale(Vector3 s)
	{
		return MakeScale(s.x, s.y, s.z);
	};

	Matrix4 MathClasses::Matrix4::Transposed()
	{
		return Matrix4(
			m1, m5, m9, m13,
			m2, m6, m10, m14,
			m3, m7, m11, m15,
			m4, m8, m12, m16);
	}

	float Matrix4::operator[](int index)
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
		case 9:
			return m10;
			break;
		case 10:
			return m11;
			break;
		case 11:
			return m12;
			break;
		case 12:
			return m13;
			break;
		case 13:
			return m14;
			break;
		case 14:
			return m15;
			break;
		case 15:
			return m16;
			break;

		}
	}

		Matrix4 MathClasses::operator*(Matrix4 a, Matrix4 b)
		{
			return Matrix4(
				a.m1 * b.m1 + a.m5 * b.m2 + a.m9 * b.m3 + a.m13 * b.m4,
				a.m2 * b.m1 + a.m6 * b.m2 + a.m10 * b.m3 + a.m14 * b.m4,
				a.m3 * b.m1 + a.m7 * b.m2 + a.m11 * b.m3 + a.m15 * b.m4,
				a.m4 * b.m1 + a.m8 * b.m2 + a.m12 * b.m3 + a.m16 * b.m4,

				a.m1 * b.m5 + a.m5 * b.m6 + a.m9 * b.m7 + a.m13 * b.m8,
				a.m2 * b.m5 + a.m6 * b.m6 + a.m10 * b.m7 + a.m14 * b.m8,
				a.m3 * b.m5 + a.m7 * b.m6 + a.m11 * b.m7 + a.m15 * b.m8,
				a.m4 * b.m5 + a.m8 * b.m6 + a.m12 * b.m7 + a.m16 * b.m8,

				a.m1 * b.m9 + a.m5 * b.m10 + a.m9 * b.m11 + a.m13 * b.m12,
				a.m2 * b.m9 + a.m6 * b.m10 + a.m10 * b.m11 + a.m14 * b.m12,
				a.m3 * b.m9 + a.m7 * b.m10 + a.m11 * b.m11 + a.m15 * b.m12,
				a.m4 * b.m9 + a.m8 * b.m10 + a.m12 * b.m11 + a.m16 * b.m12,

				a.m1 * b.m13 + a.m5 * b.m14 + a.m9 * b.m15 + a.m13 * b.m16,
				a.m2 * b.m13 + a.m6 * b.m14 + a.m10 * b.m15 + a.m14 * b.m16,
				a.m3 * b.m13 + a.m7 * b.m14 + a.m11 * b.m15 + a.m15 * b.m16,
				a.m4 * b.m13 + a.m8 * b.m14 + a.m12 * b.m15 + a.m16 * b.m16);
		}

		Vector4 MathClasses::operator*(Matrix4 a, Vector4 b)
		{
			return Vector4(
				Vector4(a.m1, a.m5, a.m9, a.m13).Dot(b),
				Vector4(a.m2, a.m6, a.m10, a.m14).Dot(b),
				Vector4(a.m3, a.m7, a.m11, a.m15).Dot(b),
				Vector4(a.m4, a.m8, a.m12, a.m16).Dot(b));
		}

		bool MathClasses::operator==(Matrix4 a, Matrix4 b)
		{
			for (int i = 0; i < 4; i++) {
				if (fabsf(a[i] - b[i]) <= .0001) {
					continue;
				}
				else {
					return false;
				}

			}
			return true;
		}

		bool MathClasses::operator!=(Matrix4 a, Matrix4 b)
		{
			return !(a == b);
		}
}