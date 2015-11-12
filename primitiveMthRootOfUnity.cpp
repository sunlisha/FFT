#include <iostream>
#include <complex.h>
#include <cmath>

using namespace std;
# define PI           3.14159265358979323846  /* pi */
typedef complex<double> dcomp; 


dcomp * primitiveMthRootOfUnity(int toneSize) {

	static dcomp * omegaN;
    omegaN = (dcomp *)malloc(toneSize * sizeof(dcomp));

    double omegaReal = cos(2*PI/toneSize);
    double omegaImag = sin(2*PI/toneSize);

    for (int index = 0; index < toneSize; index++) {
 		// omegaN[index] = cos(2*PI/toneArray[index])+ index*sin(2*PI/toneArray[index]);
 		omegaN[index] = pow(dcomp(omegaReal, omegaImag), index);

 		// omegaN[index] = dcomp();
    }
    // cout << endl << cos(2*PI/1) << endl;

    return omegaN;
}