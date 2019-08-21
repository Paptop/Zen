#include "Src/Application/PC/Desktop.h"

#include "Src/Graphics/OpenGL/Shaders/ZShaderGL.h"
#include "Src/Core/Utils/ZType.h"

#include "Src/Core/IO/ZFileLoader.h"

#include "Src/Core/Math/ZVector.h"

#include "GL/glew.h"

float triangle[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f
};

Zen::Math::ZVectorN<float, 3> points[] =
{
	{-0.5f, -0.5f, 0.0f },
	{ 0.0f,  0.5f, 0.0f },
	{ 0.5f, -0.5f, 0.0f }
};

u32 VBO, VAO;

Zen::Desktop::Desktop()
: _pcShader(nullptr)
{
	std::string vertexSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Vertex_Sh.vert");
	std::string fragSrc = IO::ZFileLoader::LoadTextFile("Src/Graphics/OpenGL/Shaders/source/Default_Frag_Sh.frag");
	_pcShader = new ZShaderGL(vertexSrc.c_str(), fragSrc.c_str());

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
	glDrawArrays(GL_TRIANGLES, 0, 3);
}