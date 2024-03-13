 #include <iostream> // cout, endl 
 #include <fstream> // ofstream, ifstream 
 using namespace std;

int main() {
ofstream out("test.txt");// make an output file object

if (!out) { // if failed to open the file 
cout << "cannot open test.text\n";
return 1; // quit the program
}
out << "R " << 9.9 << endl;
out << "T " << 4.9 << "\n";
out << "M " << 4.88 << endl;
out.close();  // close the file

ifstream in("test.txt"); //input

if(!in){
    cout << "Cannot open test.txt file.\n"; // error message
    return 1;
}

char item[20]; // print parameter
float cost;

in >> item >> cost; // read txt file
cout << item << " " << cost << "\n"; // print 
in >> item >> cost;
cout << item << " " << cost << "\n";
in >> item >> cost;
cout << item << " " << cost << "\n";

in.close();
return 0;
}