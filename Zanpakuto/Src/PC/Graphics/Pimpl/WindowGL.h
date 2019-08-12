#pragma once

#include "Src/Interfaces/IWindowImp.h"

struct GLFWwindow;

namespace Zan
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