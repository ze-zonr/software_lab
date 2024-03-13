#include <iostream>
#include <fstream>
using namespace std;

int main(void){

    ofstream out("test.txt"); // create test.txt 

    if(!out){
        cout << "cannot open test.txt\n"; // error message 
        return 1;
    }

    out << "R " << 9.9 << endl;
    out << "T " << 4.9 << "\n";
    out << "M " << 4.88 << endl;

    out.close(); // close file
}