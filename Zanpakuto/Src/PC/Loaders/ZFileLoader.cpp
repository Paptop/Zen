#include "Src/PC/Loaders/ZFileLoader.h"

#include <fstream>

#include "Src/Includes/ZUtils.h"
#include "Src/Includes/DebugUtils.h"

std::string Zan::ZFileLoader::LoadTextFile(const char* path)
{
	std::fstream input;
	input.open(path);
	
	std::string line;
	std::string output;

	bool isPositionDefined = false;

	ASSERT(input.is_open(), "File not found");
	while (getline(input, line, '\0'))
	{
		output += line;
	}

	return output;
}