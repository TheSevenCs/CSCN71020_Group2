#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" char* analyzeRectangle(POINT* arr);
extern "C" int* angleCalculator(int* sides);

namespace PolygonCheckerTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		
		TEST_METHOD()
		{
		}
	};

	TEST_CLASS(TriangleTests)
	{
	public:

		TEST_METHOD()
		{
		}
	};
}
