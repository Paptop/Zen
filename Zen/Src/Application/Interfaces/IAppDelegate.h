#pragma once

namespace Zen
{
	class IAppDelegate
	{
	public:
		virtual void Tick(float fDelta) = 0;
		virtual void Render() = 0;
	};
}