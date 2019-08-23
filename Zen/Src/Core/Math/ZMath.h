#pragma once

#include <math.h>

#define eps 0.0001

namespace Zen
{
	bool IsNearlyEqual(float A, float B, float precision = eps);
}