#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void CSVToVector(const string& inputFile, vector<int>& inputVector) {
    ifstream fin;
    string inputInteger;

    fin.open(inputFile);
    if (!fin.is_open()) {
        cout << "Error opening " << inputFile << endl;
        exit(EXIT_FAILURE);
    }

    getline(fin, inputInteger,',');
    while(!fin.fail()){
        inputVector.push_back(stoi(inputInteger));
        getline(fin, inputInteger,',');
    }
    fin.close();
}

int ComputeVectorAverage(const vector<int>& inputVec) {
    int sum{0}, count{0};
    for (int i: inputVec) {
        sum += i;
        count ++;
    }
    return (sum/count);
}

void VectorToCSV(const string& inputFile, const vector<int>& inputVector) {
    ofstream fout;
    fout.open(inputFile);

    int vectorAverage = ComputeVectorAverage(inputVector);

    if (!fout.is_open()) {
        cout << "Error opening " << inputFile << endl;
        exit(EXIT_FAILURE);
    }

    for (auto ii = inputVector.begin(); ii != inputVector.end(); ii++) {
        fout << *ii - vectorAverage;
        if (fout.fail()) {
            break;
        }
        if(ii != inputVector.end() - 1) {
            fout << ',';
        }
        if (fout.fail()) {
            break;
        }
        
    }

    fout.close();

}


int main(int argc, char *argv[]) {
    string inputFile;
    string outputFile;

    vector<int> inputVector;

    inputFile = argv[1];
    outputFile = argv[2];

    CSVToVector(inputFile, inputVector);
    VectorToCSV(outputFile, inputVector);
    return 0;
}