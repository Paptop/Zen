#pragma once

#include <string>

namespace Zan
{
	class ZFileLoader
	{
	public:
		static std::string LoadTextFile(const char* path);
	};
}