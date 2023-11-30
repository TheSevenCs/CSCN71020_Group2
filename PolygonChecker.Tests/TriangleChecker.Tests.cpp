#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/point.h"
#define TRIANGLE_SIDES_ARRAY_SIZE 3
#define TRIANGLE_ANGLES_ARRAY_SIZE 3

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" char* analyzeRectangle(POINT* arr);
extern "C" int* angleCalculator(int* sides);
extern "C" char* analyzeTriangle(int side1, int side2, int side3);

namespace TriangleCheckerTests
{
	TEST_CLASS(GoodValuesAnalyzeTriangleTests)
	{
	public:

		TEST_METHOD(Sides_10_10_15_Return_Isosceles_triangle) //Tests that the analyze triangle function correctly returns isoceles with good inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 10,10,15 };
			char *expected = "Isosceles triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected,result);
		}
		TEST_METHOD(Sides_10_10_10_Return_Equilateral_triangle) //Tests that the analyze triangle function correctly returns equilateral with good inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 10,10,10 };
			char* expected = "Equilateral triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(Sides_10_12_15_Return_Scalene_triangle) //Tests that the analyze triangle function correctly returns scalene with good inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 10,12,15 };
			char* expected = "Scalene triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(NegativeValuesAnalyzeTriangleTests)
	{
	public:
		TEST_METHOD(Sides_Negative8_10_15_DoesNotReturn_Scalene_triangle) // Tests that the analyeTriangle function doesnt return scalene with 1 bad input
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -8,10,15 };
			char* notExpected = "Scalene triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notExpected, result);
		}

		TEST_METHOD(Sides_Negative8_Negative20_10_DoesNotReturn_Scalene_triangle) // Tests that the analyeTriangle function doesnt return scalene with 2 bad inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -8,-20,10 };
			char* notExpected = "Scalene triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			bool notEqual = (result == notExpected);
			//Assert
			Assert::IsFalse(notEqual);
		}

		TEST_METHOD(Sides_Negative4_Negative2_Negative12_DoesNotReturn_Scalene_triangle) // Tests that the analyeTriangle function doesnt return scalene with 3 bad inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -4,-2,-12 };
			char* notExpected = "Scalene triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			bool notEqual = (result == notExpected);
			//Assert
			Assert::IsFalse(notEqual);
		}

		TEST_METHOD(Sides_10_Negative10_15_DoesNotReturn_Isosceles_triangle) // Tests that the analyeTriangle function doesnt return Isoceles with 1 bad input
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 10,-10,15 };
			char* notexpected = "Isosceles triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}

		TEST_METHOD(Sides_Negative5_Negative5_10_DoesNotReturn_Isosceles_triangle) // Tests that the analyeTriangle function doesnt return Isoceles with 2 bad inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -5,-5,10 };
			char* notexpected = "Isosceles triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}

		TEST_METHOD(Sides_Negative15_Negative15_Negative23_DoesNotReturn_Isosceles_triangle) // Tests that the analyeTriangle function doesnt return Isoceles with 3 bad input
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -15,-15,-23 };
			char* notexpected = "Isosceles triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}

		TEST_METHOD(Sides_Negative1_1_1_DoesNotReturn_Equilateral_triangle) // Tests that the analyeTriangle function doesnt return equilateral with 1 bad input
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -1,1,1 };
			char* notexpected = "Equilateral triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}

		TEST_METHOD(Sides_Negative2_Negative2_2_DoesNotReturn_Equilateral_triangle) // Tests that the analyeTriangle function doesnt return equilateral with 2 bad inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -2,-2,2 };
			char* notexpected = "Equilateral triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}

		TEST_METHOD(Sides_Negative10_Negative10_Negative10_DoesNotReturn_Equilateral_triangle) // Tests that the analyeTriangle function doesnt return equilateral with 3 bad inputs
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -10,-10,-10 };
			char* notexpected = "Equilateral triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreNotEqual(notexpected, result);
		}
	};

	TEST_CLASS(NotATriangleAnalyzeTriangleTests)
	{
	public:
		TEST_METHOD(Sides_0_0_0_Return_Not_a_triangle) // Tests that the analyze triangleFunction returns "Not A triangle" with three 0s
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 0,0,0 };
			char* expected = "Not a triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			//Assert
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Sides_1_2_0_Return_Not_a_triangle) // Tests that the analyze triangleFunction returns "Not A triangle" with one 0
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 1,2,0 };
			char* expected = "Not a triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			bool notEqual = (expected != result);
			//Assert
			Assert::IsFalse(notEqual);
		}

		TEST_METHOD(Sides_0_0_10_Return_Not_a_triangle) // Tests that the analyze triangleFunction returns "Not A triangle" with two 0s
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 0,0,10 };
			char* expected = "Not a triangle";
			//Act
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			bool equal = (result == expected);
			//Assert
			Assert::IsTrue(equal);
		}
	};

	TEST_CLASS(GoodInputTriangleAngleCalculatorTests)
	{
	public:
		TEST_METHOD(Sides_5_6_10_Return_27_22_131) // This is for a scalene triangle with the side lengths 5, 6, 10
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 5, 6, 10 };
			int expectedAngles[TRIANGLE_ANGLES_ARRAY_SIZE] = { 27,22,131 };
			bool passed = true;
			//Act
			int *results = angleCalculator(sides);
			for (int i = 0; i < TRIANGLE_ANGLES_ARRAY_SIZE; i++)
			{
				if (results[i] != expectedAngles[i])
				{
					passed = false;
				}
			}
			//Assert
			Assert::IsTrue(passed);
		}
		TEST_METHOD(Sides_500_500_707_Return_45_45_90) //A right angle isoceles triangle should return the angles 45 45 90
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 500, 500, 707 };
			int expectedAngles[TRIANGLE_ANGLES_ARRAY_SIZE] = { 45,45,90 };
			bool passed = true;
			//Act
			int* results = angleCalculator(sides);
			for (int i = 0; i < TRIANGLE_ANGLES_ARRAY_SIZE; i++)
			{
				if (results[i] != expectedAngles[i])
				{
					passed = false;
				}
			}
			//Assert
			Assert::IsTrue(passed);
		}

		TEST_METHOD(Sides_30_30_30_Return_60_60_60) //Equalateral Triangle should give back 3 60 degrees angles
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 30, 30, 30 };
			int expectedAngles[TRIANGLE_ANGLES_ARRAY_SIZE] = { 60,60,60 };
			bool passed = true;
			//Act
			int* results = angleCalculator(sides);
			for (int i = 0; i < TRIANGLE_ANGLES_ARRAY_SIZE; i++)
			{
				if (results[i] != expectedAngles[i])
				{
					passed = false;
				}
			}
			//Assert
			Assert::IsTrue(passed);
		}
	};
	TEST_CLASS(TriangleAnglesAddUpTo180Tests)
	{
	public:
		TEST_METHOD(Sides_30_30_30_Return_AnglesThatAddUpTo180) //Equalateral Triangle should give back 3 60 degrees angles
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 30, 30, 30 };
			int expectedAngleSum = 180;
			int actualAngleSum = 0;

			//Act
			int* results = angleCalculator(sides);
			for (int i = 0; i < TRIANGLE_ANGLES_ARRAY_SIZE; i++)
			{
				actualAngleSum += results[i];
			}
			//Assert
			Assert::AreEqual(expectedAngleSum, actualAngleSum);
		}

		TEST_METHOD(Sides_25_50_30_Return_AnglesThatAddUpTo180) //Random god inputs should give back 3 60 degrees angles
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 25, 50, 30 };
			int expectedAngleSum = 180;
			int actualAngleSum = 0;

			//Act
			int* results = angleCalculator(sides);
			for (int i = 0; i < TRIANGLE_ANGLES_ARRAY_SIZE; i++)
			{
				actualAngleSum += results[i];
			}
			//Assert
			Assert::AreEqual(expectedAngleSum, actualAngleSum);
		}
	};
	TEST_CLASS(InvalidTriangleAngleCalculatorTests)
	{
	public:
		TEST_METHOD(Sides_30_30_100_Return_Negative1) //A triangle cannot have the sum of two side lengths less than a 3rd side length
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 30, 30, 100 };
			int *expected = (int*) - 1;

			//Act
			int* results = angleCalculator(sides);

			//Assert
			Assert::AreEqual(expected, results);
		}

		TEST_METHOD(Sides_30_30_Negative100_Return_Negative1) //Previous test but with a negative integer
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 30, 30, -100 };
			int* expected = (int*)-1;

			//Act
			int* results = angleCalculator(sides);

			//Assert
			Assert::AreEqual(expected, results);
		}

		TEST_METHOD(Sides_Negative15_20_50_Return_Negative1) //Checking if it will bypass the sum check if one of the sums is a negative integer 
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -15, 20, 50 };
			int* expected = (int*)-1;

			//Act
			int* results = angleCalculator(sides);

			//Assert
			Assert::AreEqual(expected, results);
		}

		TEST_METHOD(Sides_Negative10_Negative8_40_Return_Negative1) // Testing if two negative integers bypasses the sum check
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -10, -8, 40 };
			int* expected = (int*)-1;

			//Act
			int* results = angleCalculator(sides);

			//Assert
			Assert::AreEqual(expected, results);
		}

		TEST_METHOD(Sides_Negative20_Negative20_Negative41_Return_Negative1) // Testing if all sides are negative
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { -20, -20, -41 };
			int* expected = (int*)-1;

			//Act
			int* results = angleCalculator(sides);

			//Assert
			Assert::AreEqual(expected, results);
		}

		TEST_METHOD(Sides_20_20_40_Return_Negative1) // Checks that it still returns -1 if the sum of the first two inputs is equal to the third (it has to be greater)
		{
			//Arrange
			int sides[TRIANGLE_SIDES_ARRAY_SIZE] = { 20, 20, 40 };
			int* expected = (int*)-1;

			//Act
			int* results = angleCalculator(sides);

			//Assert
			Assert::AreEqual(expected, results);
		}
	};
}
