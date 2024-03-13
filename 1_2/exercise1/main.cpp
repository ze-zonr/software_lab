#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class waveHeader {
public:
    waveHeader() {};
    int chuckID, chunkSize, Format, subChunkID, subChunk1size;
    short audioFormat, numChannels;
    int sampleRate, byteRate;
    short blockAlign, bitsPerSample;
    int subChunk2ID, subChunk2size;
};

int main(){
    ifstream xx("Beatles.wav", ios::binary | ios::in);
    if(!xx) return 999; // error message
    waveHeader myHeader;
    xx.read((char*)&myHeader, sizeof(waveHeader));
    cout << "   sampleRate= " << myHeader.sampleRate << endl; // return sampleRate
    xx.close();
}