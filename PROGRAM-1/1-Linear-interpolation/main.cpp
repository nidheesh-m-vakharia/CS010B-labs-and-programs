#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);
void SwapElementsByIndex(vector<double> &, size_t, size_t);

int main(int argc, char* argv[]) {

    string  inputFile = argv[1]; // Source of data file from command line
    vector<double> angleVector; //Stores flight path angels
    vector<double> liftVector; //Stores lift for correspondiing data
    bool isContinue = true;
    string userDecision;
    bool singleElement = false;


    double userInputFlightAngle;

    readData(inputFile, angleVector, liftVector);

    if (angleVector.size() == 1)
    {
        singleElement = true;
    }

    if (!isOrdered(angleVector))
    {
        reorder(angleVector, liftVector);
    }

    while(isContinue) {

        cout << "Enter flight angle: ";
        cin >> userInputFlightAngle;
        cout << '\n';

        if (singleElement) {
            if (!(userInputFlightAngle == angleVector[0])) {
                cout << "Error: Value cannot be interpolated" << endl;
                return 0;
            }
        }

        if (angleVector.empty()) {
            cout << "Error: Value cannot be calculated; No value in vector" << endl;
            return 0;
        }

        if (userInputFlightAngle > angleVector.back() || userInputFlightAngle < angleVector.front()) {
            cout << "Error: Value out of bounds, try again" << endl;
            return 0;
        }

        cout << interpolation(userInputFlightAngle, angleVector, liftVector) << endl;

        do {
            cout << "Do you want to enter another flight angle? ";
            cin >> userDecision; 
        } while (userDecision != "No" && userDecision != "no" && userDecision != "Yes" && userDecision != "yes");

        
        if (userDecision == "No" || userDecision == "no") {
            break;
        }
    }
    return 0;
}

void readData(const string & fileName, vector<double> & angleVector, vector<double> & liftVector){
    ifstream datInputStream;
    double angle;
    double lift;

    datInputStream.open(fileName);

    if (!datInputStream.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    datInputStream >> angle;
    while (!datInputStream.fail())
    {
        angleVector.push_back(angle);
        datInputStream >> lift;
        if (!datInputStream.fail()) {
            liftVector.push_back(lift);
            datInputStream >> angle;
        }
    }

    datInputStream.close();
    
}

void SwapElementsByIndex (vector<double> & inputVector, size_t index1, size_t index2) {
    double temp = inputVector[index1];
    inputVector[index1] = inputVector[index2];
    inputVector[index2] = temp;
}

void reorder(vector<double> & angleVector, vector<double> & liftVector){
    for (size_t i = 0; i + 1 < angleVector.size(); i++) {
        size_t smallerElementIndex = i;

        for (size_t j = i + 1; j < angleVector.size(); j++) {
            if (angleVector[j] < angleVector[smallerElementIndex]) {
                smallerElementIndex = j;
            }
        }

        SwapElementsByIndex(angleVector, i, smallerElementIndex);
        SwapElementsByIndex(liftVector, i, smallerElementIndex);
    }
}

bool isOrdered(const vector<double> & inputVector){
    for(size_t i = 0; i + 1 != inputVector.size(); i++) {
        if (inputVector[i] > inputVector[i + 1]) {
            return false;
        }
    }

    return true;
}

double interpolation(double userAngleValue, const vector<double> & angleVector, const vector<double> & liftVector) {
    double lowerAngle, upperAngle;
    double lowerLift, upperLift;

    // Check for exact match first
    for (size_t i = 0; i < angleVector.size(); i++) {
        if (angleVector[i] == userAngleValue) {
            return liftVector[i];  // Return directly if found
        }
    }

    size_t lowerAngleIndex = 0;
    while (lowerAngleIndex + 1 < angleVector.size() && angleVector[lowerAngleIndex + 1] <= userAngleValue) {
        lowerAngleIndex++;
    }
    lowerAngle = angleVector[lowerAngleIndex];
    upperAngle = angleVector[lowerAngleIndex + 1];
    
    lowerLift = liftVector[lowerAngleIndex];
    upperLift = liftVector[lowerAngleIndex + 1];

    double slope = (upperLift - lowerLift) / (upperAngle - lowerAngle);

    return lowerLift + slope * (userAngleValue - lowerAngle);
}
