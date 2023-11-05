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
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2: // 05 NOV
			printf_s("Rectangle selected.\n");
			POINT RectanglePoints[4];
			getRectanglePoints(RectanglePoints);

			char* result1 = analyzeRectangle(RectanglePoints);
			printf_s("%s\n", result1);
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
	printf_s("\n");
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
POINT* getRectanglePoints(POINT RectanglePoints[]) {
	printf_s("A rectangle require four points in coordinate system, each takes 2 input for 2D-coordinate. \n");
	
	for (int i = 0; i < 4; i++)
	{
		float x, y;
		printf_s("Enter x and y values in x,y format for point %d :\n", i+1);
		int numConverted = scanf_s("%f,%f", &x, &y);  // TODO: format check 

		RectanglePoints[i].x = x;
		RectanglePoints[i].y = y;
	}
	return RectanglePoints;
}

