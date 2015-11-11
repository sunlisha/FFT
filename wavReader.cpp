#include <iostream>
#include <fstream>
#include <String>

using namespace std;


typedef struct  WAV_HEADER  {
							    char 	RIFF[4];        // RIFF Header      Magic header
							    int     ChunkSize;      // RIFF Chunk Size  
							    char    WAVE[4];        // WAVE Header      

							    char    fmt[4];         // FMT header       
							    int     Subchunk1Size;  // Size of the fmt chunk                                
							    short   AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 
							    short   NumOfChan;      // Number of channels 1=Mono 2=Sterio                   
							    int     SamplesPerSec;  // Sampling Frequency in Hz                             
							    int     bytesPerSec;    // bytes per second 
							    short   blockAlign;     // 2=16-bit mono, 4=16-bit stereo 
							    short   bitsPerSample;  // Number of bits per sample   

							    char    Subchunk2ID[4]; // "data"  string   
							    int     Subchunk2Size;  // Sampled data length    

							}wav_hdr; 

// Function prototypes 
int getFileSize(FILE *inFile); 
int FFT(int A, int m, int omegaN) ;

int wavReader(const char* fileName){
    wav_hdr wavHeader;
    FILE *wavFile;
    int headerSize = sizeof(wav_hdr),filelength = 0;

    wavFile = fopen(fileName, "r");

    if(wavFile == NULL){
        printf("Can not able to open wave file\n");
    }



    fread(&wavHeader,headerSize,1,wavFile);
    filelength = getFileSize(wavFile);

    cout << "File is                    :" << filelength << " bytes." << endl;

    cout << "RIFF header                :" << wavHeader.RIFF[0] 
                                            << wavHeader.RIFF[1] 
                                            << wavHeader.RIFF[2] 
                                            << wavHeader.RIFF[3] << endl;

    cout << "WAVE header                :" << wavHeader.WAVE[0] 
                                            << wavHeader.WAVE[1] 
                                            << wavHeader.WAVE[2] 
                                            << wavHeader.WAVE[3] 
                                            << endl;

    cout << "FMT                        :" << wavHeader.fmt[0] 
                                            << wavHeader.fmt[1] 
                                            << wavHeader.fmt[2] 
                                            << wavHeader.fmt[3] 
                                            << endl;

    cout << "Data size                  :" << wavHeader.ChunkSize << endl;

    // Display the sampling Rate form the header
    cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
    cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
    cout << "Number of channels         :" << wavHeader.NumOfChan << endl;
    cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
    cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
    cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
    // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 


    cout << "Block align                :" << wavHeader.blockAlign << endl;

    cout << "Data string                :" << wavHeader.Subchunk2ID[0] 
                                            << wavHeader.Subchunk2ID[1]
                                            << wavHeader.Subchunk2ID[2] 
                                            << wavHeader.Subchunk2ID[3] 
                                            << endl;

    int bytesPerSample = (wavHeader.bitsPerSample)/8;
    int numberOfSamples = ((filelength - sizeof(wav_hdr)) / bytesPerSample) / 2;
	int sampleArray [numberOfSamples];

	cout << filelength - sizeof(wav_hdr) << endl;
	cout << "Bytes per sample: " << bytesPerSample << endl;
	cout << "Number of samples: " << numberOfSamples << endl;

    FILE * outputFile;

    outputFile = fopen("output.txt", "wb");

    while (!feof(wavFile))
    {
            fread(sampleArray,bytesPerSample,numberOfSamples,wavFile);        // Reading data in chunks of bytesPerSample
            fwrite(sampleArray,bytesPerSample,numberOfSamples,outputFile);
    }

    fclose(outputFile);

    cout << "numberOfSamples: " << numberOfSamples << endl;
    for (int i = 0; i < numberOfSamples; i++) {
    	cout << sampleArray[i] << " ";
    }

    // int w = cos(2*pi/16400) ;
    // FFT(sampleArray, 16400, w) ;

    fclose(wavFile);

    int index = 0;
    int highestFrequency = wavHeader.SamplesPerSec / 2;

    cout << endl << endl << endl << "First Tone: " << endl << endl << endl;

    int offset;

    int firstToneSize = highestFrequency * 0.1;
    int firstTone[firstToneSize];

    offset = firstToneSize;
    cout << endl << "Offset1: " << offset << endl;

    for (int i = 0; i < firstToneSize; i++) {
        firstTone[index] = sampleArray[i];
        cout << firstTone[index] << " ";
        index++;
    }

    int firstGapSize = highestFrequency * 0.05;

    offset = offset + firstGapSize;
    cout << endl << "Offset2: " << offset << endl;

    cout << endl << endl << endl << "Second Tone: " << endl << endl << endl;


    int secondToneSize = highestFrequency * 0.1;
    int secondTone[secondToneSize];

    index = 0;
    for (int i = 0 + offset; i < secondToneSize + offset; i++) {
        secondTone[index] = sampleArray[i];
        cout << secondTone[index] << " ";
        index++;
    }

    offset = offset + secondToneSize;
    cout << endl << "Offset3: " << offset << endl;

    int secondGapSize = highestFrequency * 1.05;

    offset = offset + secondGapSize;
    cout << endl << "Offset4: " << offset << endl;

    cout << endl << endl << endl << "Third Tone: " << endl << endl << endl;

    int thirdToneSize = highestFrequency * 0.1;
    int thirdTone[thirdToneSize];

    index = 0;
    for (int i = 0 + offset; i < thirdToneSize + offset; i++) {
        thirdTone[index] = sampleArray[i];
        cout << thirdTone[index] << " ";
        index++;
    }

    offset = offset + thirdToneSize;
    cout << endl << "Offset5: " << offset << endl;

    int thirdGapSize = highestFrequency * 0.05;

    offset = offset + thirdGapSize;
    cout << endl << "Offset6: " << offset << endl;

    cout << endl << endl << endl << "Fourth Tone: " << endl << endl << endl;

    int fourthToneSize = highestFrequency * 0.1;
    int fourthTone[fourthToneSize];

    offset = offset + fourthToneSize;
    cout << endl << "Offset7: " << offset << endl;

    index = 0;
    for (int i = 0 + offset; i < fourthToneSize + offset; i++) {
        fourthTone[index] = sampleArray[i];
        cout << fourthTone[index] << " ";
        index++;
    }

    cout << endl << endl << endl << "Fifth Tone: " << endl << endl << endl;

    int fourthGapSize = highestFrequency * 0.05;

    offset = offset + fourthGapSize;
    cout << endl << "Offset8: " << offset << endl;

    int fifthToneSize = highestFrequency * 0.1;
    int fifthTone[fifthToneSize];


    index = 0;
    for (int i = 0 + offset; i < fifthToneSize + offset; i++) {
        fifthTone[index] = sampleArray[i];
        cout << fifthTone[index] << " ";
        index++;
    }

    offset = offset + fifthToneSize;
    cout << endl << "Offset9: " << offset << endl;

    cout << endl << endl << endl << "Sixth Tone: " << endl << endl << endl;

    int fifthGapSize = highestFrequency * 0.05;

    offset = offset + fifthGapSize;
    cout << endl << "Offset10: " << offset << endl;

    int sixthToneSize = highestFrequency * 0.1;
    int sixthTone[sixthToneSize];

    index = 0;
    for (int i = 0 + offset; i < sixthToneSize + offset; i++) {
        sixthTone[index] = sampleArray[i];
        cout << sixthTone[index] << " ";
        index++;
    }

    offset = offset + sixthToneSize;
    cout << endl << "Offset11: " << offset << endl;

    cout << endl << endl << endl << "Seventh Tone: " << endl << endl << endl;

    int sixthGapSize = highestFrequency * 0.05;

    offset = offset + sixthGapSize;
    cout << endl << "Offset12: " << offset << endl;

    int seventhToneSize = highestFrequency * 0.1;
    int seventhTone[sixthToneSize];


    index = 0;
    for (int i = 0 + offset; i < seventhToneSize + offset; i++) {
        seventhTone[index] = sampleArray[i];
        cout << sixthTone[index] << " ";
        index++;
    }

    return 0;
} 
// find the file size 
int getFileSize(FILE *inFile){
    int fileSize = 0;
    fseek(inFile,0,SEEK_END);

    fileSize=ftell(inFile);

    fseek(inFile,0,SEEK_SET);
    return fileSize;
}

