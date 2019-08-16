#include "Src/Core/Math/ZVector.h"

#include <math.h>

Zen::Math::ZVector::ZVector()
: _x(0)
, _y(0)
, _z(0)
, _w(1)
{
}

Zen::Math::ZVector::ZVector(float x, float y, float z, float w)
: _x(x)
, _y(y)
, _z(z)
, _w(w)
{
}

float Zen::Math::ZVector::Mag()
{
	return sqrt(MagSquared());
}

float Zen::Math::ZVector::MagSquared()
{
	return _x * _x + _y * _y + _z * _z;
}

Zen::Math::ZVector& Zen::Math::ZVector::operator+=(const ZVector& vector)
{
	_x += vector._x; _y += vector._y; _z += vector._z;
	return *this;
}

Zen::Math::ZVector& Zen::Math::ZVector::operator-=(const ZVector& vector)
{
	_x -= vector._x; _y -= vector._y; _z -= vector._z;
	return *this;
}

Zen::Math::ZVector& Zen::Math::ZVector::operator*=(const ZVector& vector)
{
	_x *= vector._x; _y *= vector._y; _z *= vector._z;
	return *this;
}

Zen::Math::ZVector& Zen::Math::ZVector::operator/=(const ZVector& vector)
{
	_x /= vector._x; _y /= vector._y; _z /= vector._z;
	return *this;
}


Zen::Math::ZVector Zen::Math::ZVector::operator+(const ZVector& vector)
{
	ZVector res;
	res += vector;
	return res;
}

Zen::Math::ZVector Zen::Math::ZVector::operator-(const ZVector& vector)
{
	ZVector res;
	res -= vector;
	return res;
}

Zen::Math::ZVector Zen::Math::ZVector::operator*(const ZVector& vector)
{
	ZVector res;
	res *= vector;
	return res;
}

Zen::Math::ZVector Zen::Math::ZVector::operator/(const ZVector& vector)
{
	ZVector res;
	res /= vector;
	return res;
}