#pragma once

#include <string>

namespace Zen { namespace IO {

		class ZFileLoader
		{
		public:
			static std::string LoadTextFile(const char* path);
		};
}}