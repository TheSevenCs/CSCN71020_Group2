#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"
#include "quadrilateralSolver.h"

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

bool isATriangle(int* sides, int* hypotneuseIndex)
{
	int hypotenuse = 0;
	for (int i = 0; i < NUM_OF_SIDES_ON_TRIANGLE; i++)
	{
		if (hypotenuse < sides[i])
		{
			hypotenuse = sides[i];
			hypotneuseIndex == i; //saves hypotneuse location
		}
	}
	if (sides[0] + sides[1] + sides[2] - hypotenuse >= hypotenuse) // The sum of two of the sides have to be greater than the hypotneuse for it to be a triangle
	{
		return true;
	}
	else
	{
		return false;
	}
}
int* angleCalculator(int* sides, int* hypotneuseIndex)
{
	int c = hypotneuseIndex, a, b, temp;
	int angles[3];

	if (!isATriangle) // Checks that its a triangle first
	{
		return -1;
	}
	if (c == 3) // The if statements determine which two side lengths will be side a and b using side c as a reference
	{
		a = 1, b = 2;
	}
	else if (c == 2)
	{
		a = 1, b = 3;
	}
	else if (c == 1)
	{
		a = 2, b = 3;
	}
	angles[2] = acos((pow(sides[a], 2) + pow(sides[b], 2) - pow(sides[c], 2)) / 2 * sides[a] * sides[b]) * 180.0 / M_PI; // Calculates angle C of the rectangle with the knowledge of the largest side length using the equation cosC = a^2 + b^2 - c^2 / 2ab
	
	temp = sin(angles[2]) / sides[c]; // Calculates c/sinC for the next equation
	angles[0] = asin(temp * sides[a]) * 180.0 / M_PI; //Calculates for angle A using equation a/sinA = c/sinC

	angles[1] = 180 - (angles[0] + angles[2]); // Uses the priciple that all 3 angles of a triangle have to equal up to 180 degrees to calculate the last angle (angle b)
	return angles;
}