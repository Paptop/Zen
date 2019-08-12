#include <stdio.h>
#include <stdlib.h>

#include "Src/PC/Loaders/ZFileLoader.h"

#include "Src/Includes/ZUtils.h"
#include "Src/Includes/DebugUtils.h"

const char* Zan::ZFileLoader::LoadTextFile(const char* path)
{
	char* buffer = NULL;
	FILE* fp = NULL;
	size_t size = 0;

	/* Open your_file in read-only mode */
	fopen_s(&fp, path, "r");

	if (fp == nullptr)
	{
		ASSERT(false, "Failed to open a file");
	}

	/* Get the buffer size */
	fseek(fp, 0, SEEK_END); /* Go to end of file */
	size = ftell(fp); /* How many bytes did we pass ? */

	/* Set position of stream to the beginning */
	rewind(fp);

	/* Allocate the buffer (no need to initialize it with calloc) */
	buffer = (char*)malloc((size + 1) * sizeof(*buffer)); /* size + 1 byte for the \0 */
	ASSERT(buffer != NULL, "Malloc failed");

	/* Read the file into the buffer */
	fread(buffer, size, 1, fp); /* Read 1 chunk of size bytes from fp into buffer */

	/* NULL-terminate the buffer */
	ASSERT(ArrayLen<char>(buffer) > 0, "Array is empty");

	buffer[size] = '\0';

	return buffer;
}