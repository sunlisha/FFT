#include <iostream>
#include <fstream>
#include <String>
#include <cmath>
#include "wavReader.cpp"
#include "splitWav.cpp"
#include "primitiveMthRootOfUnity.cpp"

using namespace std;

# define PI           3.14159265358979323846  /* pi */

int main() {
	int sampleRate;
	short * wavArray;

	wavArray = wavReader("message.wav", sampleRate);

	int index;
    int offset = 0;
    int toneSize = sampleRate * 0.1;
    int gapSize;
	short *ptr[7];

    for(int i = 0; i < 7; i++) {
        if (i != 1) {
            gapSize = sampleRate * 0.05;
        }
        else {
            gapSize = sampleRate * 1.05;
        }
        ptr[i] = splitWav(i+1, toneSize, offset, wavArray);

        offset = offset + toneSize;

        gapSize = gapSize;

        offset = offset + gapSize;
    }

    int m = toneSize;

    double * omegaN[7];

    for (int i = 0; i < 7; i++) {
 		omegaN[i] = primitiveMthRootOfUnity(ptr[i], m);
    }
	 	

 	cout << endl << omegaN[0][3] << endl;

	return 0;
}