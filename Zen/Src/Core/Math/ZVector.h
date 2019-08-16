#pragma once
#include <math.h>

namespace Zen { namespace Math {

		template<class T>
		struct ZVector4
		{
		public:
			T _x, _y, _z, _w;

			ZVector4()
			{
			}

			ZVector4(T x, T y, T z, T w)
			: _x(x)
			, _y(y)
			, _z(z)
			, _w(w)
			{
			}

			T Mag()
			{
				return sqrt(MagSquared());
			}

			T MagSquared()
			{
				return _x * _x + _y * _y + _z * _z;
			}

			ZVector4<T>& operator+=(const ZVector4& vector)
			{
				_x += vector._x; _y += vector._y; _z += vector._z;
				return *this;
			}

		
			ZVector4<T>& operator-=(const ZVector4& vector)
			{
				_x -= vector._x; _y -= vector._y; _z -= vector._z;
				return *this;
			}

	
			ZVector4<T>& operator*=(const ZVector4& vector)
			{
				_x *= vector._x; _y *= vector._y; _z *= vector._z;
				return *this;
			}

	
			ZVector4<T>& operator/=(const ZVector4& vector)
			{
				_x /= vector._x; _y /= vector._y; _z /= vector._z;
				return *this;
			}


			ZVector4<T> operator+(const ZVector4& vector)
			{
				ZVector4 res;
				res += vector;
				return res;
			}

			ZVector4<T> operator-(const ZVector4& vector)
			{
				ZVector4 res;
				res -= vector;
				return res;
			}


			ZVector4<T> operator*(const ZVector4& vector)
			{
				ZVector4 res;
				res *= vector;
				return res;
			}

			ZVector4<T> operator/(const ZVector4& vector)
			{
				ZVector4 res;
				res /= vector;
				return res;
			}
		};


		// Vector Operations
		template<typename T>
		T dot(const ZVector4<T>& vec0, const ZVector4<T>& vec1)
		{
			return vec0._x * vec1._x + vec0._y * vec1._y + vec0._z * vec1._z;
		}
}}
