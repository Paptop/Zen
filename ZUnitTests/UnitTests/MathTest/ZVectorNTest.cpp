#include "pch.h"

#include "Src/Core/Math/ZVector.h"

TEST(Math_VectorN_Mag_0, MathZ)
{
	ZVector3 vec3(1.0f , 2.0f , 3.0f);
	float fMag = vec3.Mag();
	EXPECT_TRUE(Zen::IsNearlyEqual(3.74166f, fMag));
}

TEST(Math_VectorN_Mag_1, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3(1.0f , 2.0f , 3.0f);
	float fMag = vec3.MagSquared();
	EXPECT_EQ(fMag, 14);
}

TEST(Math_VectorN_Plus, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(3.0f, 3.0f, 0.0f);

	ZVector3 vec3_2 = vec3_0 + vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Minus, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(-1.0f, 1.0f, 6.0f);

	ZVector3 vec3_2 = vec3_0 - vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Mult, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(2.0f, 2.0f, -9.0f);
	
	ZVector3 vec3_2 = vec3_0 * vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Div, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(0.5f, 2.0f, -1.0f);
	
	ZVector3 vec3_2 = vec3_0 / vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Plus_Assign, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(3.0f, 3.0f, 0.0f);

	vec3_0 += vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Minus_Assign, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(-1.0f, 1.0f, 6.0f);

	vec3_0 -= vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Mult_Assign, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(2.0f, 2.0f, -9.0f);

	vec3_0 *= vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Div_Assign, MathZ)
{
	ZVector3 vec3_0(1.0f, 2.0f, 3.0f);
	ZVector3 vec3_1(2.0f, 1.0f, -3.0f);
	ZVector3 vec3_r(0.5f, 2.0f, -1.0f);

	vec3_0 /= vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Dot, MathZ)
{
	ZVector3 vec3_0(1, 3, -5);
	ZVector3 vec3_1(4, -2, -1);

	int scalar = vec3_0.dot(vec3_1);

	EXPECT_EQ(scalar, 3);
}

TEST(Math_VectorN_Normalize, MathZ)
{
	ZVector3 vec3(3.0f, 1.0f, 2.0f);

	float mag = vec3.Mag();
	vec3.Normalize();

	ZVector3 vec3_r(0.80f, 0.26f, 0.53f);

	EXPECT_TRUE(vec3.IsNearlyEq(vec3_r, 0.01f));
}