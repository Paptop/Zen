#pragma once

namespace Zan
{
	struct ZVector
	{
	public:
		float _x, _y, _z, _w;

		ZVector();
		ZVector(float x, float y, float z, float w);

		float Mag();
		float MagSquared();

		ZVector& operator+=(const ZVector& vector);
		ZVector& operator-=(const ZVector& vector);
		ZVector& operator*=(const ZVector& vector);
		ZVector& operator/=(const ZVector& vector);

		ZVector operator+(const ZVector& vector);
		ZVector operator-(const ZVector& vector);
		ZVector operator*(const ZVector& vector);
		ZVector operator/(const ZVector& vector);
	};
}
