#include "Src/Core/IO/ZFileLoader.h"
#include "Src/Core/IO/external/stb_image.h"

#include <fstream>

#include "Src/Core/Debug/DebugUtils.h"


std::string Zen::IO::ZFileLoader::LoadTextFile(const char* path)
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

byte* Zen::IO::ZFileLoader::LoadImage(const std::string& path, int& width, int& height)
{
	stbi_set_flip_vertically_on_load(true);
	int nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	return data;
}

void Zen::IO::ZFileLoader::FreeImage(byte* data)
{
	stbi_image_free(data);
}