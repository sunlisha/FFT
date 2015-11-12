#include <iostream>

using namespace std;
# define PI           3.14159265358979323846  /* pi */


double * primitiveMthRootOfUnity(short * toneArray, int toneSize) {

	static double* omegaN;
    omegaN = (double *)malloc(toneSize * sizeof(double));

    for (int i = 0; i < toneSize; i++) {
 		omegaN[i] = cos(2*PI/toneArray[i]) + i*sin(2*PI/toneArray[i]);
    }

    return omegaN;
}