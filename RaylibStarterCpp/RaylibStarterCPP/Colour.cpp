#include "Colour.h"

//hello

namespace MathClasses
{
	std::string MathClasses::Colour::ToString() const
	{
		return std::string();
	}

	MathClasses::Colour::Colour()
	{
		colour = 0xff;
	}

	MathClasses::Colour::Colour(Byte r, Byte g, Byte b, Byte a)
	{
		colour = (r << 24) | (g << 16) | (b << 8) | (a);
	}

	Byte MathClasses::Colour::GetRed() const
	{
		return (colour >> 24) &0xff;
	}

	Byte MathClasses::Colour::GetGreen() const
	{
		return (colour >> 16) &0xff;
	}

	Byte MathClasses::Colour::GetBlue() const
	{
		return (colour >> 8) &0xff;
	}

	Byte MathClasses::Colour::GetAlpha() const
	{
		return colour &0xff;
	}

	void Colour::RedToGreen()
	{
		SetGreen(GetRed());
	}

	void MathClasses::Colour::SetRed(Byte v)
	{
		colour = (colour & 0x00'ff'ff'ff) | (v << 24);
	}

	void MathClasses::Colour::SetGreen(Byte v)
	{
		colour = (colour & 0xff'00'ff'ff) | (v << 16);

	}

	void MathClasses::Colour::SetBlue(Byte v)
	{
		colour = (colour & 0xff'ff'00'ff) | (v << 8);

	}

	void MathClasses::Colour::SetAlpha(Byte v)
	{
		colour = (colour & 0xff'ff'ff'00) | v;

	}

	bool MathClasses::operator==(Colour a, Colour b)
	{
		return (a.colour == b.colour);
	}

	bool MathClasses::operator!=(Colour a, Colour b)
	{
		return !(a == b);
	}


}