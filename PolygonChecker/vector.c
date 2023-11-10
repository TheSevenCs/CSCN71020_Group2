//CSCN71020 - Group2 - zongping cui - Chris Mitskas - 05 NOV 
#pragma once
#include "vector.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Constructor
// 05 NOV
VECTOR CreateVectorByPoint(POINT a, POINT b) {
	VECTOR v;
	//VECTOR* ptrV = (VECTOR*)malloc(sizeof(VECTOR));
	//if (ptrV == NULL) {
	//	fprintf(stderr, "error allocating memory\n");
	//	return NULL;  // NULL pointer
	//}
	float x = b.x - a.x;
	float y = b.y - a.y;
	v.x = x;
	v.y = y;
	v.length = sqrt(x * x + y * y);
	return v;

}

// returns true if the two vectors are equal within the precision range
// 05 NOV
bool IsVectorEqual(VECTOR a, VECTOR b) {

	if (fabs(a.length - b.length) < ACCURACY && fabs(a.x - b.x) < ACCURACY && fabs(a.y - b.y) < ACCURACY) {
		return true;
	}

	return false;
}