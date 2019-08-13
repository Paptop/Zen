#include "Src/PC/Desktop.h"

#include "Src/PC/Graphics/Shaders/ZShader.h"
#include "Src/Includes/ZType.h"

#include "Src/PC/Loaders/ZFileLoader.h"

#include "GL/glew.h"

float triangle[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f
};

u32 VBO, VAO;

Zan::Desktop::Desktop()
: _pcShader(nullptr)
{
	std::string vertexSrc = ZFileLoader::LoadTextFile("Src/PC/Graphics/Shaders/source/Default_Vertex_Sh.vert");
	std::string fragSrc = ZFileLoader::LoadTextFile("Src/PC/Graphics/Shaders/source/Default_Frag_Sh.frag");
	_pcShader = new ZShaderGL(vertexSrc.c_str(), fragSrc.c_str());

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Zan::Desktop::~Desktop()
{
}

void Zan::Desktop::Tick(float fDelta)
{
}

void Zan::Desktop::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	_pcShader->Use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}