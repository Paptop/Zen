#pragma once

#include "Src/Application/Interfaces/IAppDelegate.h"

namespace Zen
{
	class ZShaderGL;

	class Desktop : public IAppDelegate 
	{
	public:
		Desktop();
		~Desktop();

		virtual void Tick(float fDelta) override;
		virtual void Render() override;
	private:
		ZShaderGL* _pcShader;
	};
}