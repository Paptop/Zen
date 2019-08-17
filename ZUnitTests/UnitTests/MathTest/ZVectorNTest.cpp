#include "pch.h"

#include "Src/Core/Math/ZMath.h"
#include "Src/Core/Math/ZVector.h"

TEST(Math_VectorN_Mag_0, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3(1.0f , 2.0f , 3.0f);
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
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(3.0f, 3.0f, 0.0f);

	Zen::Math::ZVectorN<float, 3> vec3_2 = vec3_0 + vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Minus, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(-1.0f, 1.0f, 6.0f);

	Zen::Math::ZVectorN<float, 3> vec3_2 = vec3_0 - vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Mult, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(2.0f, 2.0f, -9.0f);

	Zen::Math::ZVectorN<float, 3> vec3_2 = vec3_0 * vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Div, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(0.5f, 2.0f, -1.0f);

	Zen::Math::ZVectorN<float, 3> vec3_2 = vec3_0 / vec3_1;

	EXPECT_TRUE(vec3_2 == vec3_r);
}

TEST(Math_VectorN_Plus_Assign, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(3.0f, 3.0f, 0.0f);

	vec3_0 += vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Minus_Assign, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(-1.0f, 1.0f, 6.0f);

	vec3_0 -= vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Mult_Assign, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(2.0f, 2.0f, -9.0f);

	vec3_0 *= vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Div_Assign, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3_0(1.0f, 2.0f, 3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_1(2.0f, 1.0f, -3.0f);
	Zen::Math::ZVectorN<float, 3> vec3_r(0.5f, 2.0f, -1.0f);

	vec3_0 /= vec3_1;

	EXPECT_TRUE(vec3_0 == vec3_r);
}

TEST(Math_VectorN_Dot, MathZ)
{
	Zen::Math::ZVectorN<int, 3> vec3_0(1, 3, -5);
	Zen::Math::ZVectorN<int, 3> vec3_1(4, -2, -1);

	int scalar = vec3_0.dot(vec3_1);

	EXPECT_EQ(scalar, 3);
}

TEST(Math_VectorN_Normalize, MathZ)
{
	Zen::Math::ZVectorN<float, 3> vec3(3.0f, 1.0f, 2.0f);

	float mag = vec3.Mag();
	vec3.Normalize();
	Zen::Math::ZVectorN<float, 3> vec3_r(0.80f, 0.26f, 0.53f);


	EXPECT_TRUE(vec3.IsNearlyEq(vec3_r, 0.01f));
}