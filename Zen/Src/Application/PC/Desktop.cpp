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

ZVector3 triangle[] =
{
	//Pos					//Colour
	{1.0f,  -1.0f, 0.0f},  {1.0f,  0.0f, 0.0f},
	{-1.0f, -1.0f, 0.0f},  {0.0f,  1.0f, 0.0f},
	{0.0f,   1.0f, 0.0f }, {0.0f,  0.0f, 1.0f}
};


u32 VBO, VAO;

Zen::Desktop::Desktop()
: _pcShader(nullptr)
{
	std::string vertexSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Vertex_Sh.vert");
	std::string fragSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Frag_Sh.frag");
	_pcShader = new ZShaderGL(vertexSrc.c_str(), fragSrc.c_str());

	DivideTriangle(triangle[0], triangle[1],
				   triangle[2], triangle[3],
				   triangle[4], triangle[5], iSubdivide);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(ZVector3), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(ZVector3), (void*)(1 * sizeof(ZVector3)));
	glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	_pcShader->Use();
	//_pcShader->SetVec4("colour", { 1.0f,0.0f,0.0f,1.0f });
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
	glDrawArrays(GL_TRIANGLES, 0, iNumVertices);
}