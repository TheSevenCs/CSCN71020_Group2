//CSCN71020 - Group2 - zongping cui - 05 NOV 
#include "vector.h"
#include "quadrilateralSolver.h"
#include <stdio.h>
#include <math.h>


#define M_PI 3.14159265358979323846

// private function to calculate the angle between two vectors using acos
double getCornerByTwoVector(VECTOR ab, VECTOR ac) {
	// take b as corner point

	double cosA = (ab.x * ac.x + ab.y * ac.y) / (ab.length * ac.length);

	double angle = acos(cosA) * 180/ M_PI;
	
	return angle;
}


char* analyzeRectangle(POINT* arr) {
	char* result = "Not sure yet";
	bool is_rectangle = false;
	
	VECTOR ab = CreateVectorByPoint(*(arr), *(arr + 1));
	VECTOR ac = CreateVectorByPoint(*(arr), *(arr + 2));
	VECTOR ad = CreateVectorByPoint(*(arr), *(arr + 3));

	double angle_bac = getCornerByTwoVector(ab, ac); // angle of bac

	double angle_bad = getCornerByTwoVector(ab, ad); // angle of bad

	double angle_cad = getCornerByTwoVector(ac, ad); // angle of cad

	if (fabs(angle_bac - 90) < ACCURACY) { // angle bac = 90,  if vector ab = cd, then the shape is rectangle
		VECTOR cd = CreateVectorByPoint(*(arr + 2), *(arr + 3));
		if (IsVectorEqual(ab, cd)) 
			is_rectangle = true;
	}
	else if (fabs(angle_bad - 90) < ACCURACY) { // angle bad = 90,  if vector ab = dc, then the shape is rectangle
		VECTOR dc = CreateVectorByPoint(*(arr + 3), *(arr + 2));
		if (IsVectorEqual(ab, dc))
			is_rectangle = true;
	}
	else if (fabs(angle_cad - 90) < ACCURACY) { // angle cad = 90,  if vector ac = db, then the shape is rectangle
		VECTOR db = CreateVectorByPoint(*(arr + 3), *(arr + 1));
		if (IsVectorEqual(ac, db))
			is_rectangle = true;
	}

	// return msg
	if(is_rectangle)
		result = "Rectangle";
	else
		result = "Not a rectangle";

	return result;
}