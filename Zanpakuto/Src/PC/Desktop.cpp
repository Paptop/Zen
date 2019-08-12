#include "Src/PC/Desktop.h"

#include "GL/glew.h"

Zan::Desktop::Desktop()
{
}

Zan::Desktop::~Desktop()
{
}

void Zan::Desktop::Tick(float fDelta)
{
}

void Zan::Desktop::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}