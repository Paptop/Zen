#pragma once

#include "Src/PC/Graphics/Interfaces/IWindow.h"

namespace Zan
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

	private:
		IWindowImp* _impl;
	};
}