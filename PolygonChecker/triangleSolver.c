#include <stdio.h>
#include <stdlib.h>
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
			*hypotneuseIndex = i; //saves hypotneuse location
		}
	}
	if (sides[0] + sides[1] + sides[2] - hypotenuse > hypotenuse) // The sum of two of the sides have to be greater than the hypotneuse for it to be a triangle
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
	int c[1], a, b, temp;
	int angles[3];

	if (!isATriangle(sides, c)) // Checks that its a triangle first
	{
		return -1;
	}
	if (*c == 2) // The if statements determine which two side lengths will be side a and b using side c as a reference
	{
		b = 0, a = 1;
	}
	else if (*c == 1)
	{
		b = 0, a = 2;
	}
	else if (*c == 0)
	{
		b = 1, a = 2;
	}
	else
	{
		b = 0, a = 1;
	}
	// Calculate angles in radians from side length
	double angleA = acos(((double)sides[b] * (double)sides[b] + ((double)sides[*c] * (double)sides[*c]) - (double)sides[a] * (double)sides[a]) / (2 * (double)sides[b] * (double)sides[*c]));
	double angleB = acos(((double)sides[a] * (double)sides[a] + ((double)sides[*c] * (double)sides[*c]) - (double)sides[b] * (double)sides[b]) / (2 * (double)sides[a] * (double)sides[*c]));
	double angleC = acos(((double)sides[a] * (double)sides[a] + (double)sides[b] * (double)sides[b] - ((double)sides[*c] * (double)sides[*c])) / (2 * (double)sides[a] * (double)sides[b]));

	// Convert angles to degrees
	angles[0] = angleA * 180.0 / M_PI;
	angles[1] = angleB * 180.0 / M_PI;
	angles[2] = angleC * 180.0 / M_PI;

	return angles;
}