#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt (const string&, const char& );


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(const string& fileName, const char& selectChar) {
    ifstream fin;
    int count{0}, countOfBlank{0};

    fin.open(fileName);

    if (!fin.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    string inputString;
    fin >> inputString;

    while (!fin.fail()) {
        for (char& c: inputString) {
            if(c == selectChar) {
                count++;
            }
        }
        countOfBlank++;
        fin >> inputString;
    }

    if (selectChar == ' '){
        return --(--(--countOfBlank));
    }

    return count;
}