// Write and test by Zongping Cui, Chris Mitskas  NOV 17
#include "pch.h"
#include "CppUnitTest.h"

typedef struct vector {
	float x; 
	float y; 
	double length; 
}VECTOR;

typedef enum quadrilateral_type {
	QUADRILATERAL, RECTANGLE, CONCAVE
}QUAD_TYPE;

typedef struct point {
	float x;
	float y;
}POINT;

extern "C" bool analyzeConcaveOrLine(POINT[]);
extern "C" QUAD_TYPE analyzeQuad(POINT a[], VECTOR[]);

  

extern "C" double calculatePerimeter(VECTOR * arrV);
extern "C" VECTOR CreateVectorByPoint(POINT a, POINT b);
extern "C" double getCornerByTwoVector(VECTOR ab, VECTOR ac);
extern "C" bool IsVectorEqual(VECTOR a, VECTOR b);



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
	TEST_CLASS(Tests)
	{
	public:
		/* by chris*/
		//Test cases for creating vector by point function
		TEST_METHOD(Test_create_vector_by_point_1) //test 1
		{
			POINT a;
			POINT b;
			a.x = 0;
			a.y = 0;
			b.x = 1;
			b.y = 0;
			VECTOR vector_result1 = CreateVectorByPoint(a, b);
			Assert::AreEqual(1, 0, vector_result1.x);
			Assert::AreEqual(0, 0, vector_result1.y);
			Assert::AreEqual(1.0, vector_result1.length);

		}
		TEST_METHOD(Test_create_vector_by_point_2) // test 2
		{
			POINT a;
			POINT b;
			a.x = 0;
			a.y = 0;
			b.x = -3;
			b.y = 0;
			VECTOR vector_result1 = CreateVectorByPoint(a, b);
			Assert::AreEqual(-3, 0, vector_result1.x);
			Assert::AreEqual(0, 0, vector_result1.y);
			Assert::AreEqual(3.0, vector_result1.length);

		}
		TEST_METHOD(Test_create_vector_by_point_3) //test 3
		{
			POINT a;
			POINT b;
			a.x = 0;
			a.y = 0;
			b.x = 0;
			b.y = 0;
			VECTOR vector_result1 = CreateVectorByPoint(a, b);
			Assert::AreEqual(0, 0, vector_result1.x);
			Assert::AreEqual(0, 0, vector_result1.y);
			Assert::AreEqual(0.0, vector_result1.length);

		}
		//Test cases for calculating the perimeter
		TEST_METHOD(Test_calculate_perimeter_1) //test 1
		{
			VECTOR arrV[4];
			arrV[0].length = 10;
			arrV[1].length = 10;
			arrV[2].length = 10;
			arrV[3].length = 10;
			double result = calculatePerimeter(arrV);
			Assert::AreEqual(40.0, result);
		}
		TEST_METHOD(Test_calculate_perimeter_2) //test 2
		{
			VECTOR arrV[4];
			arrV[0].length = 0;
			arrV[1].length = 0;
			arrV[2].length = 0;
			arrV[3].length = 0;
			double result = calculatePerimeter(arrV);
			Assert::AreEqual(0.0, result);
		}
		TEST_METHOD(Test_calculate_perimeter_3) //test 3
		{
			VECTOR arrV[4];
			arrV[0].length = 10;
			arrV[1].length = 10;
			arrV[2].length = 10;
			arrV[3].length = -5;
			double result = calculatePerimeter(arrV);
			Assert::AreEqual(25.0, result);
		}

		//Test cases for getting corner by two vectors
		TEST_METHOD(Get_corner_by_two_vectors1) //test 1
		{
			VECTOR ab;
			VECTOR ac;
			ab.x = 1;
			ab.y = 0;
			ac.x = 0;
			ac.y = 1;
			ab.length = 1;
			ac.length = 1;
			double angle_result1 = getCornerByTwoVector(ab, ac);
			Assert::AreEqual(90.0, angle_result1);
		}
		TEST_METHOD(Get_corner_by_two_vectors2) //test 2
		{
			VECTOR ab;
			VECTOR ac;
			ab.x = 1;
			ab.y = 1;
			ac.x = 0;
			ac.y = 1;
			ab.length = 1;
			ac.length = 1;
			double angle_result1 = getCornerByTwoVector(ab, ac);
			Assert::AreEqual(0.0, angle_result1);
		}
		//tests for is is vector equal function
		TEST_METHOD(Is_vector_equal1) //test 1
		{
			VECTOR vector[2];
			vector[0] = { 1,1, 1 };
			vector[1] = { 1,2,3 };

			bool result1 = IsVectorEqual(vector[0], vector[1]);
			Assert::AreEqual(false, result1);
		}

		TEST_METHOD(Is_vector_equal2) //test 2
		{
			VECTOR vector[2];
			vector[0] = { 0,0, 0 };
			vector[1] = { 1,1,1 };

			bool result1 = IsVectorEqual(vector[0], vector[1]);
			Assert::AreEqual(false, result1);
		}
		
		TEST_METHOD(Is_vector_equal3) //test 3
		{
			//Test 0 case
			VECTOR vector[2];
			vector[0] = { 0,0, 0 };
			vector[1] = { 0,0,0 };

			bool result1 = IsVectorEqual(vector[0], vector[1]);
			Assert::AreEqual(true, result1);
		}


		/* by ping*/
		// Test analyzeConcaveOrLine()
		TEST_METHOD(TestAnalyzeConcaveFunctionality)
		{
			// test a square which is not concave
			VECTOR arrV[4];
			POINT arrP[4];
			arrP[0] = { 0,0 };
			arrP[1] = { 1,0 };
			arrP[2] = { 0,1 };
			arrP[3] = { 1,1 };

			bool x = analyzeConcaveOrLine(arrP);

			Assert::AreEqual(false, x);
			//Assert::AreEqual(expected, result);
		}		

		TEST_METHOD(TestAnalyzeConcaveUsingLine1)
		{
			// test a case when 4 point on a line, return true
			POINT arrP[4];
			arrP[0] = { 0,0 };
			arrP[1] = { 1,0 };
			arrP[2] = { 2,0 };
			arrP[3] = { 3,0 };

			bool x = analyzeConcaveOrLine(arrP);

			Assert::AreEqual(true, x);
		}

		TEST_METHOD(TestAnalyzeConcaveUsingLine2)
		{
			// test a case when 3 point on one line
			POINT arrP[4];
			arrP[0] = { 1,1 };
			arrP[1] = { 1,0 };
			arrP[2] = { 2,0 };
			arrP[3] = { 3,0 };

			bool x = analyzeConcaveOrLine(arrP);

			Assert::AreEqual(true, x);
		}

		TEST_METHOD(TestAnalyzeConcaveFunctionality3)
		{
			// test a case when it is a concave quad
			POINT arrP[4];
			arrP[0] = { 1,1 };
			arrP[1] = { 0,0 };
			arrP[2] = { 3,3 };
			arrP[3] = { -3,3 };

			bool x = analyzeConcaveOrLine(arrP);

			Assert::AreEqual(true, x);
		}	


		TEST_METHOD(TestAnalyzeConcaveFunctionality4)
		{
			// test a case when 4 point are same which is not a concave shape case and either they are on same line
			POINT arrP[4];
			arrP[0] = { 1,1 };
			arrP[1] = { 1,1 };
			arrP[2] = { 1,1 };
			arrP[3] = { 1,1 };

			bool x = analyzeConcaveOrLine(arrP);

			Assert::AreEqual(true, x);
		}

		


		// Test analyzeQuad()
		TEST_METHOD(TestAnalyzeQuadFunctionlity)
		{
			// test a case when it is a concave quad
			VECTOR retV[4];
			POINT arrP[4];

			arrP[0] = { 1,1 };
			arrP[1] = { 0,0 };
			arrP[2] = { 3,3 };
			arrP[3] = { -3,3 };

			int res = analyzeQuad(arrP, retV);
			int expected = 2;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestAnalyzeQuadUsingLine)
		{
			// test a case when 4 point on a line, return 2
			VECTOR retV[4];
			POINT arrP[4];

			arrP[0] = { 1,0 };
			arrP[1] = { 2,0 };
			arrP[2] = { 5,0 };
			arrP[3] = { 7,0 };

			int res = analyzeQuad(arrP, retV);
			int expected = 2;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestAnalyzeQuadUsingOnePoint)
		{
			// test a case when 4 point is same
			VECTOR retV[4];
			POINT arrP[4];

			arrP[0] = { 0,0 };
			arrP[1] = { 0,0 };
			arrP[2] = { 0,0 };
			arrP[3] = { 0,0 };

			int res = analyzeQuad(arrP, retV);
			int expected = 2;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestAnalyzeQuadUsingSquare)
		{
			// test a case when it is a square
			VECTOR retV[4];
			POINT arrP[4];

			arrP[0] = { 0,0 };
			arrP[1] = { 0,-3 };
			arrP[2] = { -3,0 };
			arrP[3] = { -3,-3 };

			int res = analyzeQuad(arrP, retV);
			int expected = 1;
			Assert::AreEqual(expected, res);

			Assert::AreEqual(3.0, retV[0].length);
			Assert::AreEqual(3.0, retV[1].length);
			Assert::AreEqual(3.0, retV[2].length);
			Assert::AreEqual(3.0, retV[3].length);
		}


		TEST_METHOD(TestAnalyzeQuadUsingRectangle)
		{
			// test a case when it is a rectangle
			VECTOR retV[4];
			POINT arrP[4];

			arrP[0] = { 3,0 }; //a
			arrP[1] = { 11,6 }; //b
			arrP[2] = { 0,4 }; //c
			arrP[3] = { 8,10 }; //d

			int res = analyzeQuad(arrP, retV);
			int expected = 1;

			VECTOR expV[4];
			expV[0] = { 8,6,10.0 };
			expV[1] = { -3, 4, 5.0 };
			expV[2] = { 8,6,10.0 };
			expV[3] = { -3, 4, 5.0 };

			Assert::AreEqual(expected, res);

			Assert::AreEqual(expV[0].length, retV[0].length);
			Assert::AreEqual(expV[1].length, retV[1].length);
			Assert::AreEqual(expV[2].length, retV[2].length);
			Assert::AreEqual(expV[3].length, retV[3].length);
		}
	};
}
