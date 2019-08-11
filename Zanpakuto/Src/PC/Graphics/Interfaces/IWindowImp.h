#pragma once

namespace Zan
{
	class IWindowImp
	{
	public:
		virtual bool Initialise() = 0;
		virtual bool Destroy() = 0;
		virtual void Run() = 0;
	};
};

