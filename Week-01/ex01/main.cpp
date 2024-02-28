#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int fileSum(string fileName) {
    ifstream fin;

    fin.open(fileName);

    if (!fin.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    int sum{0}, num;
    fin >> num;
    while(!fin.fail()) {
        sum += num;
        fin >> num;
    }

    fin.close();

    return sum;
}

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}