//CSCN71020 - Group2 - zongping cui - 05 NOV 
#pragma once


#include "point.h"
#include "vector.h"
#define M_PI 3.14159265358979323846
#define NUM_OF_SIDES_ON_Quadrilateral 4

typedef enum quadrilateral_type {
	QUADRILATERAL,RECTANGLE, CONCAVE  //TODO: Parallelogram,Trapezoid
}QUAD_TYPE;


double calculateArea(VECTOR,VECTOR);


QUAD_TYPE analyzeQuad(POINT a[], VECTOR[]);

bool analyzeConcave(POINT[]);

double calculatePerimeter(VECTOR[]);
