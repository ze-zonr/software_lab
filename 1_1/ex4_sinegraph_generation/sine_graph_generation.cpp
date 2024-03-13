#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.141592

using namespace std;
int main(){
    //file open
    ofstream out("test.txt"); // create test.txt 
    if(!out) {
        cout <<"Cannot open test.txt file\n"; // error message
        return -1;
    }
    //sine graph
    float t, dt, result, T, f;
    f = 220; // 220Hz
    dt = 1. / 8000.; // sampling frequency = 8kHz
    T = 10. / 200.;
    for(t = 0; t < T; t += dt){
        result = sin(2.*PI*f*t);
        out << t << " " << result << endl;
    }

    out.close(); // close file

}