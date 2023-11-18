#include "pch.h"
#include "CppUnitTest.h"


typedef struct vector {
	float x;
	float y;
	double length;
}VECTOR;


typedef struct point {
	float x;
	float y;
}POINT;

extern "C" double calculatePerimeter(VECTOR * arrV);
extern "C" VECTOR CreateVectorByPoint(POINT a, POINT b);
extern "C" double getCornerByTwoVector(VECTOR ab, VECTOR ac);
extern "C" bool IsVectorEqual(VECTOR a, VECTOR b); 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestrectangle
{
	TEST_CLASS(UnitTestrectangle)
	{
	public:
		//Test cases for creating vector by point function
		TEST_METHOD(Test_create_vector_by_point_1) //test 1
		{
			POINT a;
			POINT b ;
			a.x = 0;
			a.y = 0;
			b.x = 1;
			b.y = 0;
			VECTOR vector_result1 = CreateVectorByPoint(a, b);
			Assert::AreEqual(1,0, vector_result1.x);
			Assert::AreEqual(0,0, vector_result1.y);
			Assert::AreEqual(1.0 ,vector_result1.length); 

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
			vector[0] = {1,1, 1};
			vector[1] = { 1,2,3};

			bool result1 = IsVectorEqual(vector[0],vector[1]);
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
			VECTOR vector[2];
			vector[0] = { 0,0, 0 };
			vector[1] = { 0,0,0 };

			bool result1 = IsVectorEqual(vector[0], vector[1]);
			Assert::AreEqual(true, result1);
		}
	};
}
