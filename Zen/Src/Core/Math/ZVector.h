#pragma once
#include <math.h>

#include "Src/Core/Debug/DebugUtils.h"

#include <array>

namespace Zen { namespace Math {

		template<class T, int N>
		class ZVectorN
		{
		public:

			ZVectorN()
			{
				MakeZero();
			}

			ZVectorN(T x, T y)
			{
				ASSERT(N == 2, "Bad logic");
				_vec[0] = x;
				_vec[1] = y;
			}

			ZVectorN(T x, T y, T z)
			{
				ASSERT(N == 3, "Bad logic");
				_vec[0] = x;
				_vec[1] = y;
				_vec[2] = z;
			}

			ZVectorN(T x, T y, T z, T w)
			{
				ASSERT(N == 4, "Bad logic");
				_vec[0] = x;
				_vec[1] = y;
				_vec[2] = z;
				_vec[3] = w;
			}

			T& x()
			{
				return Element(0);
			}

			T& y()
			{
				return Element(1);
			}

			T& z()
			{
				return Element(2);
			}

			T& w()
			{
				return Element(3);
			}

			T X() const
			{
				return Element(0);
			}

			T Y() const
			{
				return Element(1);
			}

			T Z() const
			{
				return Element(2);
			}

			T W() const
			{
				return Element(3);
			}

			T& Element(int i)
			{
				ASSERT(i >= 0 && i < N, "Bad Logic");
				reutrn _vec[i];
			}

			ZVectorN(int i)
			{
				SetElements(i);
			}

			void MakeZero()
			{
				SetElements(0);
			}

			T MagSquared()
			{
				T mag = 0;

				for (int i = 0; i < N; ++i)
				{
					mag += _vec[i] * _vec[i];
				}

				return mag;
			}

			T Mag()
			{
				return sqrt(MagSquared());
			}

			ZVectorN<T, N>& operator=(const ZVectorN& rVector)
			{
				for (int i = 0; i < N; ++i)
				{
					_vec[i] = rVector._vec[i];
				}

				return *this;
			}
		
			ZVectorN<T, N>& operator+=(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] += rVector._vec[i];
				}
				return *this;
			}

			
			ZVectorN<T, N>& operator-=(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] -= rVector._vec[i];
				}
				return *this;
			}

	
			ZVectorN<T, N>& operator*=(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] *= rVector._vec[i];
				}

				return *this;
			}

	
			ZVectorN<T, N>& operator/=(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] /= rVector._vec[i];
				}

				return *this;
			}


			ZVectorN<T, N> operator+(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = rVector._vec[i] + _vec[i];
				}

				return res;
			}

			ZVectorN<T, N> operator-(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = _vec[i] - rVector._vec[i];
				}

				return res;
			}


			ZVectorN<T, N> operator*(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = _vec[i] * rVector._vec[i];
				}

				return res;
			}

			ZVectorN<T, N> operator/(const ZVectorN& rVector)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = _vec[i] / rVector._vec[i];
				}

				return res;
			}

			ZVectorN<T, N>& operator+=(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] += rVector._vec[i];
				}
				return *this;
			}


			ZVectorN<T, N>& operator-=(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] -= scalar
				}
				return *this;
			}


			ZVectorN<T, N>& operator*=(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				for (int i = 0; i < N; ++i)
				{
					_vec[i] *= scalar;
				}

				return *this;
			}

			ZVectorN<T, N> operator+(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = rVector._vec[i] + scalar;
				}

				return res;
			}

			ZVectorN<T, N> operator-(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = _vec[i] - scalar;
				}

				return res;
			}


			ZVectorN<T, N> operator*(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = _vec[i] * scalar;
				}

				return res;
			}

			ZVectorN<T, N> operator/(T scalar)
			{
				ASSERT(rVector._vec.size() == _vec.size(), "Bad logic");

				ZVectorN<T, N> res;

				for (int i = 0; i < N; ++i)
				{
					res._vec[i] = _vec[i] / scalar;
				}

				return res;
			}

			bool operator==(const ZVectorN& rVector)
			{
				if (rVector._vec.size() != _vec.size())
				{
					return false;
				}

				bool Equal = true;

				for (int i = 0; i < N; ++i)
				{
					Equal &= _vec[i] == rVector._vec[i];
				}

				return Equal;
			}

			bool operator!=(const ZVectorN& rVector)
			{
				return !(this == rVector);
			}

			// Vector operations

			T dot(const ZVectorN& vector)
			{
				ASSERT(_vec.size() == vector._vec.size(), "Bad logic");

				T res = 0;

				for (int i = 0; i < N; ++i)
				{
					res += _vec[i] * vector._vec[i];
				}

				return res;
			}

			T Normalize()
			{

			}

		private:
			
			void SetElements(int iNum)
			{
				for (int i = 0; i < N; ++i)
				{
					_vec[i] = (T)iNum;
				}
			}

		private:
			std::array<T, N> _vec;
		};

}}
