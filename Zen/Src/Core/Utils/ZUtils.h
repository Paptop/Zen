#pragma once

namespace Zen
{
	template <class T>
	int ArrayLen(T a[])
	{
		return sizeof(a) / sizeof(T);
	}
}