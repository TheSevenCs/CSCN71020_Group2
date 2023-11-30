#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "quadrilateralSolver.h"

//int side = 0;


int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n\n");
			int triangleSides[3] = { 0, 0, 0 };
			int *triangleAngles;
			getTriangleSides(triangleSides);

			char* result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);
			printf_s("\nTriangle type: %s\n", result);
			triangleAngles = angleCalculator(triangleSides);
			if (triangleAngles == -1) {
				break;
			}
			
			printf_s("The angles of the triangle are: %d, %d, %d", triangleAngles[0], triangleAngles[1], triangleAngles[2]);
			break;
		case 2: // 05 NOV
			printf_s("Rectangle selected.\n\n");
			double perimeter;
			POINT QuadPoints[4];
			getQuadPoints(QuadPoints);
			printf_s("\n");
			
			VECTOR arrV[NUM_OF_SIDES_ON_Quadrilateral];

			switch (analyzeQuad(QuadPoints, arrV)) 
			{
			case RECTANGLE:
				perimeter = calculatePerimeter(arrV);
				printf_s("It is a rectangle, Perimeter: %lf , Area: %lf.\n", perimeter, calculateArea(arrV[0], arrV[1])); 
				break;
			case QUADRILATERAL:
				perimeter = calculatePerimeter(arrV);
				printf_s("It is not a rectangle, Perimeter: %lf.\n", perimeter);
				break;
			case CONCAVE:
				printf_s("It is not a quadrilateral or is a concave shape, no definite perimeter.\n"); 
				break;
			default:
				printf_s("WARN: No shape match.\n");
				
			}
		
			break; 
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			//rewind(stdin);
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

// take 4 points in 2D-coordinate system from user, order insensitive
// 05 NOV
POINT* getQuadPoints(POINT QuadPoints[]) {
	printf_s("\nA rectangle require four points in coordinate system, each takes 2 input for 2D-coordinate. \n");
	
	for (int i = 0; i < 4; i++)
	{
		float x, y;
		printf_s("Enter x and y values in x,y format for point %d :\n", i+1);
		int numConverted = scanf_s("%f,%f", &x, &y);  // TODO: format check 

		QuadPoints[i].x = x;
		QuadPoints[i].y = y;
	}
	return QuadPoints;
}

