#include "Src/PC/Graphics/ZWindow.h"

#include "Src/PC/Graphics/Interfaces/IWindowImp.h"

#include "Src/Includes/DebugUtils.h"

Zan::CWindow::CWindow(Zan::IWindowImp* impl)
: IWindow()
, _impl(impl)
{
}

Zan::CWindow::~CWindow()
{
	DeInit();
}

bool Zan::CWindow::Init()
{
	ASSERT(_impl != nullptr, "Implementation not set");
	return _impl->Initialise();
}

bool Zan::CWindow::DeInit()
{
	return _impl->Destroy();
}

void Zan::CWindow::Start()
{
	_impl->Run();
}

