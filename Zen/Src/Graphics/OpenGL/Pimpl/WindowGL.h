#pragma once

#include "Src/Application/Interfaces/IWindowImp.h"

struct GLFWwindow;

namespace Zen
{
	/* Glfw window implementation wrapper */

	class IAppDelegate;

	class CWindowGL : public IWindowImp
	{
	public:
		CWindowGL();

		// IWindowImp
		virtual bool Initialise() override;
		virtual bool Destroy() override;
		virtual void Run() override;
		virtual void SetDelegate(IAppDelegate* delegate) override;

	private:
		GLFWwindow*		_pcWindow;
		IAppDelegate*	_pcApplication;
	};
}