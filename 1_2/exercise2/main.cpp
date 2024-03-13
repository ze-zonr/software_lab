#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class waveHeader {
public:
    waveHeader() {};
    int chunkID, chunkSize, Format, subChunkID, subChunk1size;
    short audioFormat, numChannels;
    int sampleRate, byteRate;
    short blockAlign, bitsPerSample;
    int subChunk2ID, subChunk2size;
};

int main(void){

    waveHeader myHeader;
    short *data, leftData, rightData;
    myHeader.sampleRate = 44100;
    myHeader.numChannels = 2; //stereo
    int n = myHeader.sampleRate * 5; // for 5 seconds
    data = new short[n * myHeader.numChannels];
    float dt = 1. / (float)(myHeader.sampleRate);
    float f1 = 261.63, f2 = 329.63, A = 10000.0;
    for(int i = 0; i < n; i++){
        float t = i*dt;
        leftData = (short)(A * cos(2.*3.141592*f1*t));
        rightData = (short)(A * cos(2.*3.141592*f2*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }
    ofstream mywave("mywave.wav", ios::binary | ios::out);
    myHeader.chunkID = 1179011410;
    myHeader.chunkSize = 36 + n * myHeader.numChannels * sizeof(short);
    myHeader.Format = 1163280727;
    myHeader.subChunkID = 544501094;
    myHeader.subChunk1size = 16;
    myHeader.audioFormat = 1;
    myHeader.numChannels = 2;
    myHeader.sampleRate = 44100;
    myHeader.byteRate = myHeader.sampleRate * myHeader.numChannels * sizeof(short);
    myHeader.blockAlign = myHeader.numChannels * sizeof(short);
    myHeader.bitsPerSample = 16;
    myHeader.subChunk2ID = 1635017060;
    myHeader.subChunk2size = n * myHeader.numChannels * sizeof(short);
    mywave.write((char*)&myHeader, sizeof(waveHeader));
    mywave.write((char*)data, sizeof(short) * n * myHeader.numChannels);
    mywave.close();

    delete[] data; // 동적 할당된 메모리 해제

    return 0;

}