#include "Src/Application/PC/ZWindow.h"

#include "Src/Application/Interfaces/IAppDelegate.h"
#include "Src/Application/Interfaces/IWindowImp.h"

#include "Src/Core/Debug/DebugUtils.h"

Zen::CWindow::CWindow(Zen::IWindowImp* impl)
: IWindow()
, _impl(impl)
{
}

Zen::CWindow::~CWindow()
{
	DeInit();
}

bool Zen::CWindow::Init()
{
	ASSERT(_impl != nullptr, "Implementation not set");
	return _impl->Initialise();
}

bool Zen::CWindow::DeInit()
{
	return _impl->Destroy();
}

void Zen::CWindow::Start()
{
	_impl->Run();
}

void Zen::CWindow::SetApplication(IAppDelegate* delegate)
{
	_impl->SetDelegate(delegate);
}


