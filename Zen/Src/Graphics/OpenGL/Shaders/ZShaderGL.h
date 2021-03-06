#pragma once

#include "Src/Core/Utils/ZType.h"
#include "Src/Core/Math/ZVector.h"

#include "GL/glew.h"

namespace Zen
{
	class ZShaderGL
	{
	public:
		ZShaderGL(const GLchar* vertexShader, const GLchar* fragmentShader);

		void SetVec4(const std::string& name, const ZVector4& vec4) const;
		void SetBool(const std::string& name, bool value)			const;
		void SetInt(const std::string& name, int value)				const;
		void SetFloat(const std::string& name, float value)			const;

		void Use();

	private:
		int CreateAndCompile(GLenum shaderType, const GLchar* src);
		int CreateProgram(u32 vertexShader, u32 fragmentShader);
	private:
		//program id;
		u32 _iID;
	};
}