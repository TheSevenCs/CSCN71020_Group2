#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/point.h"
#define TRIANGLE_SIDES_ARRAY_SIDE 3

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" char* analyzeRectangle(POINT* arr);
extern "C" int* angleCalculator(int* sides);
extern "C" char* analyzeTriangle(int side1, int side2, int side3);

namespace PolygonCheckerTests
{
	/*TEST_CLASS(RectangleTests)
	{
	public:
		
		TEST_METHOD()
		{
		}
	};*/

	TEST_CLASS(GoodValueAnalyzeTriangleTests)
	{
	public:

		TEST_METHOD(Sides_10_10_15_Return_Isosceles_triangle)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIDE] = { 10,10,15 };
			char *expected = "Isosceles triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected,result);
		}
		TEST_METHOD(Sides_10_10_10_Return_Equilateral_triangle)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIDE] = { 10,10,10 };
			char* expected = "Equilateral triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(Sides_10_12_15_Return_Scalene_triangle)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIDE] = { 10,12,15 };
			char* expected = "Scalene triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(BadValueAnalyzeTriangleTests)
	{
	public:
		TEST_METHOD(Sides_Negative8_10_15_DoesNotReturn_Scalene_triangle)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIDE] = { -8,10,15 };
			char* notExpected = "Scalene triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notExpected, result);
		}
		TEST_METHOD(Sides_10_Negative10_15_Return_Isosceles_triangle)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIDE] = { 10,-10,15 };
			char* notexpected = "Isosceles triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}
		TEST_METHOD(Sides_Negative10_Negative10_Negative10_Return_Equilateral_triangle)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIDE] = { -10,-10,-10 };
			char* notexpected = "Equilateral triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}
	};
}
