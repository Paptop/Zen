#pragma once

#include "Src/Interfaces/IAppDelegate.h"

namespace Zan
{
	class Desktop : public IAppDelegate 
	{
	public:
		Desktop();
		~Desktop();

		virtual void Tick(float fDelta) override;
		virtual void Render() override;
	};
}