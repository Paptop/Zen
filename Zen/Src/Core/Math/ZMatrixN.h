#pragma once

#include "Src/Core/Debug/DebugUtils.h"

namespace Zen {	namespace Math {

		template<class T, int N = 4>
		struct ZMatrixN
		{
			ZMatrixN(int i)
			{
				if (i == 0)
				{
					MakeZero();
				}
				else
				{
					MakeIdentity();
				}
			}

			T& operator()(int row, int col)
			{
				return mat[index(row, col)];
			}

			T operator()(int row, int col) const
			{
				return mat[index(row, col)];
			}


			void MakeZero()
			{
				for (int i = 0; i < N * N; ++i)
				{
					mat[i] = (T)0;
				}
			}

			void MakeIdentity()
			{
				MakeZero();
			}

			void SetDiagonal(T value)
			{
				for (int i = 0; < N; ++i)
				{
					mat[i][i] = value;
				}
			}

			int index(int row, int col)
			{
				ASSERT(row >= 0 && row < N, "Row not valid");
				ASSERT(col >= 0 && col < N, "Col not valid");
				return col + row * N;
			}


			T mat[N * N];
		};
}}