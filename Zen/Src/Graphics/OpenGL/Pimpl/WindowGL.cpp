#include "Src/Graphics/OpenGL/Pimpl/WindowGL.h"

#include "Src/Application/Interfaces/IAppDelegate.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Src/Core/Debug/DebugUtils.h"

Zen::CWindowGL::CWindowGL()
: IWindowImp()
, _pcWindow(nullptr)
, _pcApplication(nullptr)
{
}

bool Zen::CWindowGL::Initialise()
{
	if (!glfwInit())
	{
		ASSERT(false, "Failed to init");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_pcWindow = glfwCreateWindow(640, 480, "Zan", NULL, NULL);
	glfwMakeContextCurrent(_pcWindow);

	GLenum err = glewInit();
	
	if (GLEW_OK != err)
	{
		ASSERT(false, "Failed to create context");
		return false;
	}

	if (!_pcWindow)
	{
		ASSERT(false, "Failed to create a window");
		glfwTerminate();
		return false;
	}
}

bool Zen::CWindowGL::Destroy()
{
	if (_pcWindow)
	{
		glfwTerminate();
		return true;
	}

	ASSERT(false, "Wrong usage");
	return false;
}

void Zen::CWindowGL::SetDelegate(IAppDelegate* delegate)
{
	ASSERT(delegate != nullptr, "nullptr");
	_pcApplication = delegate;
}

void Zen::CWindowGL::Run()
{
	ASSERT(_pcWindow != nullptr, "Window not created, init first");
	ASSERT(_pcApplication != nullptr, "No delegate set");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(_pcWindow))
	{
		//TODO: Implement delta time;
		_pcApplication->Tick(0.1f);
		_pcApplication->Render();

		/* Swap front and back buffers */
		glfwSwapBuffers(_pcWindow);

		/* Poll for and process events */
		glfwPollEvents();
	}
}
