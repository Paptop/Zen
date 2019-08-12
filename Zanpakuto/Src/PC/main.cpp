#include "Src/PC/Graphics/ZWindow.h"
#include "Src/PC/Graphics/Pimpl/WindowGL.h"
#include "Src/PC/Desktop.h"

int main()
{
	//Implemenation
	Zan::CWindowGL openglImp;
	Zan::Desktop desktop;

	Zan::CWindow window(&openglImp);
	window.SetApplication(&desktop);

	window.Init();
	window.Start();

	return 0;
}