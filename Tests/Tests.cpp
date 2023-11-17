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

extern "C" bool analyzeConcave(POINT[]);
extern "C" QUAD_TYPE analyzeQuad(POINT a[], VECTOR[]);

  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(TestConcaveCase)
		{
			VECTOR arrV[4];
			POINT arrP[4];
			arrP[0] = { 0,0 };
			arrP[1] = { 1,0 };
			arrP[2] = { 0,1 };
			arrP[3] = { 1,1 };

			bool x = analyzeConcave(arrP);

			Assert::AreEqual(false, x);
			//Assert::AreEqual(expected, result);
		}




	};
}
