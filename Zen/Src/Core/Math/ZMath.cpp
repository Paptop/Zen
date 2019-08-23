#include "Src/Core/Math/ZMath.h"

bool Zen::IsNearlyEqual(float A, float B, float precision)
{
	return fabs(B - A) < precision;
}