#pragma once

#include "Src/Application/Interfaces/IWindow.h"

namespace Zen
{
	class IWindowImp;

	class CWindow : IWindow
	{
	public:
		CWindow(IWindowImp* impl);
		~CWindow();

		virtual bool Init()   override;
		virtual bool DeInit() override;
		virtual void Start() override;
		virtual void SetApplication(IAppDelegate* delegate) override;

	private:
		IWindowImp* _impl;
	};
}