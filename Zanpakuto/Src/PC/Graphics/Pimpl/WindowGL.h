#pragma once

#include "Src/PC/Graphics/Interfaces/IWindowImp.h"

struct GLFWwindow;

namespace Zan
{
	/* Glfw window implementation wrapper */

	class CWindowGL : public IWindowImp
	{
	public:
		CWindowGL();

		// IWindowImp
		virtual bool Initialise() override;
		virtual bool Destroy() override;
		virtual void Run() override;

	private:
		GLFWwindow* m_pcWindow;
	};
}