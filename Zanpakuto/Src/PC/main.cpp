#include "Src/PC/Graphics/ZWindow.h"
#include "Src/PC/Graphics/Pimpl/WindowGL.h"
#include "Src/PC/Desktop.h"

int main()
{
	//Implemenation
	Zan::CWindowGL openglImp;

	Zan::CWindow window(&openglImp);
	window.Init();

	Zan::Desktop desktop;
	window.SetApplication(&desktop);

	window.Start();

	return 0;
}