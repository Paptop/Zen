#pragma once

namespace Zan
{
	class IAppDelegate;

	class IWindow
	{
	public:
		virtual bool Init() = 0;
		virtual bool DeInit() = 0;
		virtual void Start() = 0;
		virtual void SetApplication(IAppDelegate* delegate) = 0;
	};

}