#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"
#define NUM_OF_SIDES_ON_TRIANGLE 3
char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0 ||
		 side1 >= side2 + side3 || side2 >= side1+side3 || side3 >= side1+side2) { //05 NOV
			result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side1 != side2)){ //05 NOV
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

bool isATriangle(int* sides)
{
	int hypotenuse = 0;
	for (int i = 0; i < NUM_OF_SIDES_ON_TRIANGLE; i++)
	{
		if (hypotenuse < sides[i])
		{
			hypotenuse = sides[i];
		}
	}
	if (sides[0] + sides[1] + sides[2] - hypotenuse >= hypotenuse)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int* angleCalculator(int* sides)
{
	if (!isATriangle)
	{
		return -1;
	}

}