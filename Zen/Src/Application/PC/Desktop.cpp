#include "Src/Application/PC/Desktop.h"

#include "Src/Graphics/OpenGL/Shaders/ZShaderGL.h"
#include "Src/Core/Utils/ZType.h"

#include "Src/Core/IO/ZFileLoader.h"

#include "Src/Core/Math/ZVector.h"

#include "GL/glew.h"

const int iSubdivide = 7;
const int iNumTriangles = 6561; // 3 ^ 10 + 1;
const int iNumVertices = 3 * iNumTriangles;

ZVector3 points[iNumVertices];
int Index = 0;

void AssembleTriangle(const ZVector3& a, const ZVector3& ca,
					  const ZVector3& b, const ZVector3& cb,
					  const ZVector3& c, const ZVector3& cc)
{
	points[Index++] = a;
	points[Index++] = ca;
	points[Index++] = b;
	points[Index++] = cb;
	points[Index++] = c;
	points[Index++] = cc;
}

void DivideTriangle(
		const ZVector3& a, const ZVector3& ca,
		const ZVector3& b, const ZVector3& cb,
		const ZVector3& c, const ZVector3& cc,  int count)
{
	if (count > 0)
	{
	//compute midpoints of sides
		ZVector3 v0 = (a + b) * 0.5f;
		ZVector3 v1 = (a + c) * 0.5f;
		ZVector3 v2 = (b + c) * 0.5f;
	//subdivide all but middle triangle
		DivideTriangle(a, ca, v0, cb, v1, cc, count - 1);
		DivideTriangle(c, ca, v1, cb, v2, cc, count - 1);
		DivideTriangle(b, ca, v2, cb, v0, cc, count - 1);
	}
	else
	{
		AssembleTriangle(a, ca, b, cb, c, cc);
	}
}

/*
float triangle[] =
{
	//Pos					//Colour			//UV
	1.0f,  -1.0f, 0.0f,  1.0f,  0.0f, 0.0f,		1.0f, 0.0f
	-1.0f, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,		0.0f, 0.0f,
	0.0f,   1.0f, 0.0f,  0.0f,  0.0f, 1.0f,		0.5f, 1.0f
};*/


float rectangle[] = {

	//  3----- 0
	//  |	   |
	//  |	   |
	//  2------1
	// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 0     
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 1	  
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 2	 
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 3

	//1.0f,  -1.0f, 0.0f,  1.0f,  0.0f, 0.0f,		1.0f, 0.0f,
	//-1.0f, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,     0.0f, 0.0f,
	//0.0f,   1.0f, 0.0f,  0.0f,  0.0f, 1.0f,		0.5f, 1.0f
};


u32 indices[] =
{
	0, 1, 2,
	2, 3, 0
};


u32 VBO, VAO, EBO, texture1, texture2;

Zen::Desktop::Desktop()
: _pcShader(nullptr)
{
	std::string vertexSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Vertex_Sh.vert");
	std::string fragSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Frag_Sh.frag");
	_pcShader = new ZShaderGL(vertexSrc.c_str(), fragSrc.c_str());

	//DivideTriangle(triangle[0], triangle[1],
				   //triangle[2], triangle[3],
				   //triangle[4], triangle[5], iSubdivide);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//Textures
	glGenTextures(1, &texture1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	byte* data = Zen::IO::ZFileLoader::LoadImage("C:\\Users\\user\\Pictures\\stone.jpg", width, height);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		ASSERT(false, "Failed to load");
	}

	Zen::IO::ZFileLoader::FreeImage(data);

	glGenTextures(1, &texture2);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	data = Zen::IO::ZFileLoader::LoadImage("C:\\Users\\user\\Pictures\\awesomeface.png", width, height);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		ASSERT(false, "Failed to load");
	}

	Zen::IO::ZFileLoader::FreeImage(data);

	_pcShader->Use();
	_pcShader->SetInt("texture1", 0);
	_pcShader->SetInt("texture2", 1);
}

Zen::Desktop::~Desktop()
{
}

void Zen::Desktop::Tick(float fDelta)
{
}

void Zen::Desktop::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
}