#include <iostream>
#include <fstream>
#include <String>
#include "wavReader.cpp"
#include "splitWav.cpp"

using namespace std;

int main() {
	int sampleRate;
	short * wavArray;

	wavArray = wavReader("message.wav", sampleRate);

	int index;
    int offset = 0;
    int toneSize = sampleRate * 0.1;
    int gapSize;
	short *ptr[7];

    for(int i = 1; i < 8; i++) {
        if (i != 2) {
            gapSize = sampleRate * 0.05;
        }
        else {
            gapSize = sampleRate * 1.05;
        }
        // splitWav(i, toneSize, offset, wavArray);
        ptr[i-1] = splitWav(i, toneSize, offset, wavArray);

        offset = offset + toneSize;
        // cout << endl << "Offset: " << offset << endl;

        gapSize = gapSize;

        offset = offset + gapSize;
        // cout << endl << "Offset: " << offset << endl;
    }

    


	return 0;
}