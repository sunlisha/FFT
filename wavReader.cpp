#include <iostream>
#include <fstream>
#include <String>


using namespace std;


short * wavReader(const char* fileName, int & sampleRate){
    ifstream wavFile;

    char    RIFF[4];        // RIFF Header      
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
    int headerSize = 44;
    int filelength = 0;

    wavFile.open(fileName);


    wavFile.read(RIFF,4);
    wavFile.read(reinterpret_cast<char*>(&ChunkSize), 4);
    wavFile.read(WAVE,4);
    wavFile.read(fmt,4);
    wavFile.read(reinterpret_cast<char*>(&Subchunk1Size), 4);
    wavFile.read(reinterpret_cast<char*>(&AudioFormat), 2);
    wavFile.read(reinterpret_cast<char*>(&NumOfChan), 2);
    wavFile.read(reinterpret_cast<char*>(&SamplesPerSec), 4);
    wavFile.read(reinterpret_cast<char*>(&bytesPerSec), 4);
    wavFile.read(reinterpret_cast<char*>(&blockAlign), 2);
    wavFile.read(reinterpret_cast<char*>(&bitsPerSample), 2);
    wavFile.read(Subchunk2ID, 4);


    filelength = ChunkSize + 8;

    // cout << "File is                    :" << filelength << " bytes." << endl;

    cout << "RIFF header                :" << RIFF[0] 
                                            << RIFF[1] 
                                            << RIFF[2] 
                                            << RIFF[3] << endl;

    cout << "Chunk size                 :" << ChunkSize << endl;

    cout << "WAVE header                :" << WAVE[0] 
                                            << WAVE[1] 
                                            << WAVE[2] 
                                            << WAVE[3] 
                                            << endl;

    cout << "FMT                        :" << fmt[0] 
                                            << fmt[1] 
                                            << fmt[2] 
                                            << fmt[3] 
                                            << endl;

    cout << "Subchunk 1 size            :" << Subchunk1Size << endl;

    cout << "Audio Format               :" << AudioFormat << endl; // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 

    cout << "Number of channels         :" << NumOfChan << endl;

    cout << "Sampling Rate              :" << SamplesPerSec << endl; // Display the sampling Rate form the header

    cout << "Number of bytes per second :" << bytesPerSec << endl;

    cout << "Block align                :" << blockAlign << endl;

    cout << "Bits per sample            :" << bitsPerSample << endl;

    cout << "Data string                :" << Subchunk2ID[0] 
                                            << Subchunk2ID[1]
                                            << Subchunk2ID[2] 
                                            << Subchunk2ID[3] 
                                            << endl;
    cout << "Subchunk 2 size            :" << Subchunk2Size << endl;


    int bytesPerSample = (bitsPerSample)/8;
    int numberOfSamples = ((filelength - headerSize) / bytesPerSample);
    // static short sampleArray [numberOfSamples];
    static short* sampleArray;
    sampleArray = (short *)malloc(numberOfSamples * sizeof(short));

    cout << "Bytes per sample: " << bytesPerSample << endl;
    cout << "Number of samples: " << numberOfSamples << endl;


    while (!wavFile.eof())
    {
            wavFile.read(reinterpret_cast<char*>(sampleArray), bytesPerSample * numberOfSamples);        // Reading data in chunks of bytesPerSample
    }

    // for (int i = 0; i < numberOfSamples; i++) {
    //  cout << sampleArray[i] << " ";
    // }

    wavFile.close();

    sampleRate = SamplesPerSec;

    free(sampleArray);

    return sampleArray;
} 