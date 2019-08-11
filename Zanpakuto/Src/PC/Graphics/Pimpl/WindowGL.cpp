#include "Src/PC/Graphics/Pimpl/WindowGL.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Src/Includes/DebugUtils.h"

Zan::CWindowGL::CWindowGL()
: IWindowImp()
, m_pcWindow(nullptr)
{
}

bool Zan::CWindowGL::Initialise()
{
	if (!glfwInit())
	{
		ASSERT(false, "Failed to init");
		return false;
	}

	m_pcWindow = glfwCreateWindow(640, 480, "Zan", NULL, NULL);

	if (!m_pcWindow)
	{
		ASSERT(false, "Failed to create a window");
		glfwTerminate();
		return false;
	}
}

bool Zan::CWindowGL::Destroy()
{
	if (m_pcWindow)
	{
		glfwTerminate();
		return true;
	}

	ASSERT(false, "Wrong usage");
	return false;
}

void Zan::CWindowGL::Run()
{
	ASSERT(m_pcWindow != nullptr, "Window not created, init first");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(m_pcWindow))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(m_pcWindow);

		/* Poll for and process events */
		glfwPollEvents();
	}
}
