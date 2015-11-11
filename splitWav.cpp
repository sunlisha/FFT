#include <iostream>
#include <fstream>
#include <String>

using namespace std;

short * splitWav(int num, int toneSize, int offset, short * sampleArray) {
    cout << endl << endl << endl << "Tone: " << num << endl << endl << endl;

    static short* tone;
    tone = (short *)malloc(toneSize * sizeof(short));
    int index = 0;

    for (int i = offset; i < offset + toneSize; i++) {
        tone[index] = sampleArray[i];
        cout << tone[index] << " ";
        index++;
    }

    return tone;
}

