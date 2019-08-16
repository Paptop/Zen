#include "Src/Application/PC/ZWindow.h"

// TODO: hide this include 
#include "Src/Graphics/OpenGL/Pimpl/WindowGL.h"

#include "Src/Application/PC/Desktop.h"

int main()
{
	//Implemenation
	Zen::CWindowGL openglImp;

	Zen::CWindow window(&openglImp);
	window.Init();

	Zen::Desktop desktop;
	window.SetApplication(&desktop);

	window.Start();

	return 0;
}