#include "Src/MathUtils/ZVector.h"

#include <math.h>

Zan::ZVector::ZVector()
: _x(0)
, _y(0)
, _z(0)
, _w(1)
{
}

Zan::ZVector::ZVector(float x, float y, float z, float w)
: _x(x)
, _y(y)
, _z(z)
, _w(w)
{
}

float Zan::ZVector::Mag()
{
	return sqrt(MagSquared());
}

float Zan::ZVector::MagSquared()
{
	return _x * _x + _y * _y + _z * _z;
}

Zan::ZVector& Zan::ZVector::operator+=(const ZVector& vector)
{
	_x += vector._x; _y += vector._y; _z += vector._z;
	return *this;
}

Zan::ZVector& Zan::ZVector::operator-=(const ZVector& vector)
{
	_x -= vector._x; _y -= vector._y; _z -= vector._z;
	return *this;
}

Zan::ZVector& Zan::ZVector::operator*=(const ZVector& vector)
{
	_x *= vector._x; _y *= vector._y; _z *= vector._z;
	return *this;
}

Zan::ZVector& Zan::ZVector::operator/=(const ZVector& vector)
{
	_x /= vector._x; _y /= vector._y; _z /= vector._z;
	return *this;
}


Zan::ZVector Zan::ZVector::operator+(const ZVector& vector)
{
	ZVector res;
	res += vector;
	return res;
}

Zan::ZVector Zan::ZVector::operator-(const ZVector& vector)
{
	ZVector res;
	res -= vector;
	return res;
}

Zan::ZVector Zan::ZVector::operator*(const ZVector& vector)
{
	ZVector res;
	res *= vector;
	return res;
}

Zan::ZVector Zan::ZVector::operator/(const ZVector& vector)
{
	ZVector res;
	res /= vector;
	return res;
}