#pragma once

namespace Zan
{
	class IWindow
	{
	public:
		virtual bool Init() = 0;
		virtual bool DeInit() = 0;
		virtual void Start() = 0;
	};

}