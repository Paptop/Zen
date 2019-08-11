#include "Src/PC/Graphics/ZWindow.h"
#include "Src/PC/Graphics/Pimpl/WindowGL.h"

int main()
{
	Zan::CWindowGL openglImp;
	Zan::CWindow window(&openglImp);

	window.Init();
	window.Start();

	return 0;
}