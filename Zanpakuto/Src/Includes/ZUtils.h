#pragma once

#include "Src/Includes/DebugUtils.h"

namespace Zan
{
	template <class T>
	int ArrayLen(T a[])
	{
		return sizeof(a) / sizeof(T);
	}
}