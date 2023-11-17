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


double calculateArea(VECTOR v1, VECTOR v2) {
	return v1.length * v2.length;
}


bool analyzeConcave(POINT arr[]) {
	
	bool is_concave = false;

	for (int i = 0;i < 4;i++) {
		/*ret_corners[i].sequence_index = i;*/
		POINT vertex = arr[i];

		VECTOR tmpV[3];
		for (int j = 0;j < 3;j++) {  // Combination C(3,1)
			int tail = i;
			int head = i + j + 1;
			head > 3 ? head -= 4 : head;
			tmpV[j] = CreateVectorByPoint(arr[tail], arr[head]);
		}

		int counting = 0;
		double angles[3];
		double corner_angle = 0;
		for (int j = 0;j < 3;j++) {  // Combination C(3,2)
			int start = j;
			int end = j + 1;
			end > 2 ? end -= 3 : end;
			double angle = getCornerByTwoVector(tmpV[start], tmpV[end]);
			angles[j] = angle;
			if (angle > 90 && fabs(angle - 90) > ACCURACY)
				counting++;
			if (corner_angle < angle)
				corner_angle = angle;  // take the largest one for corner
		}

		/*ret_corners[i].angle = corner_angle;*/

		if (counting == 2) {
			//ret_corners[i].interior = true;
			is_concave = true;
		}
	}

	return is_concave;
}

//chris - 05 Nov
QUAD_TYPE analyzeQuad(POINT arr[], VECTOR ret_arr_V[]) {
	//char* result = "Not sure yet";
	QUAD_TYPE ret = QUADRILATERAL;
	//CORNER ret_corners[NUM_OF_SIDES_ON_Quadrilateral];
	if (analyzeConcaveByAngle(arr)) {
		
		return CONCAVE;
	}
	


	VECTOR ab = CreateVectorByPoint(arr[0], arr[1]);
	VECTOR ac = CreateVectorByPoint(arr[0], arr[2]);
	VECTOR ad = CreateVectorByPoint(arr[0], arr[3]);

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
			ret = RECTANGLE;
		}	
	}
	else if (fabs(angle_bad - 90) < ACCURACY) { // angle bad = 90,  if vector ab = dc, then the shape is rectangle
		VECTOR dc = CreateVectorByPoint(*(arr + 3), *(arr + 2));
		if (IsVectorEqual(ab, dc)) {
			ret_arr_V[0] = ab;
			ret_arr_V[1] = ad;
			ret_arr_V[2] = dc;
			ret_arr_V[3] = CreateVectorByPoint(*(arr + 1), *(arr + 2)); //bc
			ret = RECTANGLE;
		}
			
  }
	else if (fabs(angle_cad - 90) < ACCURACY) { // angle cad = 90,  if vector ac = db, then the shape is rectangle
		VECTOR db = CreateVectorByPoint(*(arr + 3), *(arr + 1));
		if (IsVectorEqual(ac, db)) {
			ret_arr_V[0] = ac;
			ret_arr_V[1] = ad;
			ret_arr_V[2] = db;
			ret_arr_V[3] = CreateVectorByPoint(*(arr + 2), *(arr + 1)); //cb
			ret = RECTANGLE;
		}
			
	}

	


	if (ret != RECTANGLE) {
		VECTOR cd = CreateVectorByPoint(*(arr + 2), *(arr + 3));
		VECTOR bd = CreateVectorByPoint(*(arr + 1), *(arr + 3));
		VECTOR arrV[NUM_OF_SIDES_ON_Quadrilateral] = { ab,ac,cd,bd };
		for (int i = 0;i < NUM_OF_SIDES_ON_Quadrilateral;i++) {
			ret_arr_V[i] = arrV[i];
		}
	}

	// return msg
	return ret;
}