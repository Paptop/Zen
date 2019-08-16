#include "pch.h"

#include "Src/Core/Math/ZMath.h"
#include "Src/Core/Math/ZVector.h"

TEST(Math_Vector4_Mag_0, MathZ)
{
	Zen::Math::ZVector4<float> vec4 = { 1.0f , 2.0f , 3.0f, 1.0f };
	float fMag = vec4.Mag();
	EXPECT_TRUE(Zen::IsNearlyEqual(3.74166, fMag));
}

TEST(Math_Vector4_Mag_1, MathZ)
{
	Zen::Math::ZVector4<float> vec4 = { 1.0f , 2.0f , 3.0f, 1.0f };
	float fMag = vec4.MagSquared();
	EXPECT_TRUE(fMag, 14);
}

TEST(Math_Vector4_Dot_0, MathZ)
{
	Zen::Math::ZVector4<int> vec0 = { 9, 2, 7, 1};
	Zen::Math::ZVector4<int> vec1 = { 4, 8, 10, 1};
	
	int iScalar = Zen::Math::dot<int>(vec0, vec1);

	EXPECT_EQ(iScalar, 122);
}