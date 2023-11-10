//CSCN71020 - Group2 - zongping cui - 05 NOV 
#pragma once
#include "point.h"
#include <stdbool.h>

#define ACCURACY 1e-4

typedef struct vector {
	float x;
	float y;
	double length;
}VECTOR;

VECTOR CreateVectorByPoint(POINT,POINT);


bool IsVectorEqual(VECTOR, VECTOR);
