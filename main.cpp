#include <iostream>
#include <fstream>
#include <String>
#include <cmath>
#include <complex.h>
#include "wavReader.cpp"
#include "splitWav.cpp"
#include "primitiveMthRootOfUnity.cpp"
#include "FFT.cpp"

using namespace std;

# define PI           3.14159265358979323846  /* pi */
typedef complex<double> dcomp; 


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

    dcomp * omegaN[7];

    int iterator = 0;
    while(iterator < log2(toneSize)) {
    	m = pow(2,iterator);
    	iterator++;
    }

    for (int i = 0; i < 7; i++) {
 		omegaN[i] = primitiveMthRootOfUnity(512);
    }

    
	 	
    // cout << endl << "m: " << m << endl;
    // int start = (toneSize - m) / 2;

    // short array[m];
    // for (int i = 0; i < m; i++) {
    // 	array[i] = ptr[0][start];
    // 	cout << array[i] << " ";
    // 	start++;
    // }
 	cout << endl << omegaN[0][0] << endl;
 	cout << endl << omegaN[0][1] << endl;

 	// Complex * FFT;
 	// FFT = fft(array, m, omegaN[0]);

 	// for (int i = 0; i < m; i++) {
 	// 	cout << FFT[0] << " ";
 	// }

	return 0;
}