//CSCN71020 - Group2 - zongping cui - 05 NOV 
#include "vector.h"
#include "quadrilateralSolver.h"
#include <stdio.h>
#include <math.h>



// private function to calculate the angle between two vectors using acos
double getCornerByTwoVector(VECTOR ab, VECTOR ac) {
	// take b as corner point

	double cosA = (ab.x * ac.x + ab.y * ac.y) / (ab.length * ac.length);

	double angle = acos(cosA) * 180/ M_PI;
	
	return angle;
}

double calculatePerimeter(VECTOR* arrV) {
	
	double perimeter = 0;
	for (int i = 0; i < NUM_OF_SIDES_ON_Quadrilateral; i++) {
		VECTOR v = *(arrV + i);
		perimeter += v.length;
	}

	return perimeter;
	
}

double calculateSquare() {

}


double maxOfD(double* arr, int size) {
	float max = *arr;
	
	for (int i = 0; i < size; i++)
		if (max < *(arr + 1)) {
			max = *(arr + 1);
		}
	
	return max;
}


//chris - 05 Nov
bool analyzeRectangle(POINT* arr, VECTOR ret_arr_V[]) {
	char* result = "Not sure yet";
	bool is_rectangle = false;
	
	VECTOR ab = CreateVectorByPoint(*(arr), *(arr + 1));
	VECTOR ac = CreateVectorByPoint(*(arr), *(arr + 2));
	VECTOR ad = CreateVectorByPoint(*(arr), *(arr + 3));

	double angle_bac = getCornerByTwoVector(ab, ac); // angle of bac

	double angle_bad = getCornerByTwoVector(ab, ad); // angle of bad

	double angle_cad = getCornerByTwoVector(ac, ad); // angle of cad

	double arrD[3] = { angle_bac,angle_bad,angle_cad };


	



	if (fabs(angle_bac - 90) < ACCURACY) { // angle bac = 90,  if vector ab = cd, then the shape is rectangle
		VECTOR cd = CreateVectorByPoint(*(arr + 2), *(arr + 3));
		if (IsVectorEqual(ab, cd)) {
			ret_arr_V[0] = ab;
			ret_arr_V[1] = ac;
			ret_arr_V[2] = cd;
			ret_arr_V[3] = CreateVectorByPoint(*(arr + 1), *(arr + 3));
			is_rectangle = true;
		}	
	}
	else if (fabs(angle_bad - 90) < ACCURACY) { // angle bad = 90,  if vector ab = dc, then the shape is rectangle
		VECTOR dc = CreateVectorByPoint(*(arr + 3), *(arr + 2));
		if (IsVectorEqual(ab, dc)) {
			ret_arr_V[0] = ab;
			ret_arr_V[1] = ad;
			ret_arr_V[2] = dc;
			ret_arr_V[3] = CreateVectorByPoint(*(arr + 1), *(arr + 2)); //bc
			is_rectangle = true;
		}
			
  }
	else if (fabs(angle_cad - 90) < ACCURACY) { // angle cad = 90,  if vector ac = db, then the shape is rectangle
		VECTOR db = CreateVectorByPoint(*(arr + 3), *(arr + 1));
		if (IsVectorEqual(ac, db)) {
			ret_arr_V[0] = ac;
			ret_arr_V[1] = ad;
			ret_arr_V[2] = db;
			ret_arr_V[3] = CreateVectorByPoint(*(arr + 2), *(arr + 1)); //cb
			is_rectangle = true;
		}
			
	}

	


	if (!is_rectangle) {
		VECTOR cd = CreateVectorByPoint(*(arr + 2), *(arr + 3));
		VECTOR bd = CreateVectorByPoint(*(arr + 1), *(arr + 3));
		VECTOR arrV[NUM_OF_SIDES_ON_Quadrilateral] = { ab,ac,cd,bd };
		for (int i = 0;i < NUM_OF_SIDES_ON_Quadrilateral;i++) {
			ret_arr_V[i] = arrV[i];
		}
	}

	// return msg
	return is_rectangle;
}