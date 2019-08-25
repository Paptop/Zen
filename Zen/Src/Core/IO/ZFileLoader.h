#pragma once

#include "Src/Core/Utils/ZType.h"

#include <string>

namespace Zen { namespace IO {

		class ZFileLoader
		{
		public:
			static std::string LoadTextFile(const char* path);

			static byte* LoadImage(const std::string& path, int& width, int& height);
			static void FreeImage(byte* data);
		};
}}