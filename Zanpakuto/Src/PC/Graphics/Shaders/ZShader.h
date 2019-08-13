#pragma once

#include "Src/Includes/ZType.h"

#include "GL/glew.h"

namespace Zan
{
	class ZShaderGL
	{
	public:
		ZShaderGL(const GLchar* vertexShader, const GLchar* fragmentShader);
		void Use();

	private:
		int CreateAndCompile(GLenum shaderType, const GLchar* src);
		int CreateProgram(u32 vertexShader, u32 fragmentShader);
	private:
		//program id;
		u32 _iID;
	};
}