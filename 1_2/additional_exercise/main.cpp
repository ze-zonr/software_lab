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
    int n = myHeader.sampleRate * 8; // for 8 seconds
    int i = 0;
    data = new short[n * myHeader.numChannels];
    float dt = 1. / (float)(myHeader.sampleRate);
    float f1 = 261.63, f2 = 329.63, A = 10000.0;
    float A0 = 440, G = 392, F = 349.23;
    
    for(i = 0; i < n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = n/32; i < n/16; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = n/16; i < 3*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*F*t));
        rightData = (short)(A * cos(2.*3.141592*F*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 3*n/32; i < n/16; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = n/16; i < 5*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 5*n/32; i < 3*n/16; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 3*n/16; i < 4*n/16; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 4*n/16; i < 9*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 9*n/32; i < 5*n/16; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 5*n/16; i < 12*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 12*n/32; i < 13*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 13*n/32; i < 14*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 14*n/32; i < 16*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 16*n/32; i < 17*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 17*n/32; i < 18*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 18*n/32; i < 19*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*F*t));
        rightData = (short)(A * cos(2.*3.141592*F*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 19*n/32; i < 20*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 20*n/32; i < 21*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 21*n/32; i < 22*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 22*n/32; i < 24*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 24*n/32; i < 25*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 25*n/32; i < 26*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 26*n/32; i < 27*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*A0*t));
        rightData = (short)(A * cos(2.*3.141592*A0*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 27*n/32; i < 28*n/32; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*G*t));
        rightData = (short)(A * cos(2.*3.141592*G*t));
        data[i * 2] = leftData;
        data[i * 2 + 1] = rightData;
    }

    for(i = 28*n/32; i < n; i++){
        float t = i * dt;
        leftData = (short)(A * cos(2.*3.141592*F*t));
        rightData = (short)(A * cos(2.*3.141592*F*t));
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