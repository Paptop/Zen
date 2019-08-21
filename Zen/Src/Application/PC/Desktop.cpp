#include "Src/Application/PC/Desktop.h"

#include "Src/Graphics/OpenGL/Shaders/ZShaderGL.h"
#include "Src/Core/Utils/ZType.h"

#include "Src/Core/IO/ZFileLoader.h"

#include "Src/Core/Math/ZVector.h"

#include "GL/glew.h"

const int iSubdivide = 5;
const int iNumTriangles = 729; // 3 ^ 10 + 1;
const int iNumVertices = 3 * iNumTriangles;

ZVector3 points[iNumVertices];
int Index = 0;

void AssembleTriangle(const ZVector3& a, const ZVector3& b, const ZVector3& c)
{
	points[Index++] = a;
	points[Index++] = b;
	points[Index++] = c;
}

void DivideTriangle(const ZVector3& a, const ZVector3& b, const ZVector3 c, int count)
{
	if (count > 0)
	{
	//compute midpoints of sides
		ZVector3 v0 = (a + b) * 0.5f;
		ZVector3 v1 = (a + c) * 0.5f;
		ZVector3 v2 = (b + c) * 0.5f;
	//subdivide all but middle triangle
		DivideTriangle(a, v0, v1, count - 1);
		DivideTriangle(c, v1, v2, count - 1);
		DivideTriangle(b, v2, v0, count - 1);
	}
	else
	{
		AssembleTriangle(a, b, c);
	}
}

ZVector3 triangle[] =
{
	{-1.0f, -1.0f, 0.0f},
	{0.0f,  1.0f, 0.0f},
	{1.0f, -1.0f, 0.0f}
};


u32 VBO, VAO;

Zen::Desktop::Desktop()
: _pcShader(nullptr)
{
	std::string vertexSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Vertex_Sh.vert");
	std::string fragSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Frag_Sh.frag");
	_pcShader = new ZShaderGL(vertexSrc.c_str(), fragSrc.c_str());

	DivideTriangle(triangle[0], triangle[1], triangle[2], iSubdivide);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
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

	_pcShader->Use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, iNumTriangles);
}