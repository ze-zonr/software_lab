#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.141592

using namespace std;
int main(){
    //file open
    ofstream out("test.txt");
    if(!out) {
        cout <<"Cannot open test.txt file\n"; // error message
        return -1;
    }
    //Amplitude Modulation
    float t, dt, result, T, f0, fc;
    f0 = 100; // f0 = 100Hz
    fc = 1000; // fc = 1kHz
    dt = 1. / 8000.; // sampling frequency = 8kHz
    T = 10. / 200.;
    for(t = 0; t < T; t += dt){
        result = cos(2 * PI * fc * (1 + 0.2 * sin(2 * PI * f0 * t)) * t);
        out << t << " " << result << endl;
    }

    out.close();

}