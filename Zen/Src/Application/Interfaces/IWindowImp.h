#pragma once

namespace Zen
{
	class IAppDelegate;

	class IWindowImp
	{
	public:
		virtual bool Initialise() = 0;
		virtual bool Destroy() = 0;
		virtual void Run() = 0;
		virtual void SetDelegate(IAppDelegate* delegate) = 0;
	};
};

