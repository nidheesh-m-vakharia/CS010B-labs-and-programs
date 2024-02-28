#include <iostream>
#include "IntVector.h"

using namespace std;

int main() {
    // Default constructor test
    IntVector v1;
    cout << "Default constructor test: size = " << v1.size() << ", capacity = " << v1.capacity() << endl;

    // Constructor with capacity test
    IntVector v2(5);
    cout << "Constructor with capacity test: size = " << v2.size() << ", capacity = " << v2.capacity() << endl;

    // Constructor with capacity and value test
    IntVector v3(3, 10);
    cout << "Constructor with capacity and value test: size = " << v3.size() << ", capacity = " << v3.capacity() << endl;

    // Size, Capacity, and Empty test
    cout << "Size: " << v3.size() << endl;
    cout << "Capacity: " << v3.capacity() << endl;
    cout << "Empty: " << (v3.empty() ? "true" : "false") << endl;

    // Accessing elements using at() method
    cout << "Element at index 1: " << v3.at(1) << endl;

    // Front and Back test
    cout << "Front: " << v3.front() << endl;
    cout << "Back: " << v3.back() << endl;

    // Assign test
    v3.assign(4, 5);
    cout << "After assigning: ";
    for (unsigned i = 0; i < v3.size(); ++i) {
        cout << v3.at(i) << " ";
    }
    cout << endl;

    // Push_back and Pop_back test
    v3.push_back(20);
    cout << "After push_back: ";
    for (unsigned i = 0; i < v3.size(); ++i) {
        cout << v3.at(i) << " ";
    }
    cout << endl;
    v3.pop_back();
    cout << "After pop_back: ";
    for (unsigned i = 0; i < v3.size(); ++i) {
        cout << v3.at(i) << " ";
    }
    cout << endl;

    // Clear test
    v3.clear();
    cout << "After clear: size = " << v3.size() << endl;

    // Resize test
    v3.resize(2, 7);
    cout << "After resize: ";
    for (unsigned i = 0; i < v3.size(); ++i) {
        cout << v3.at(i) << " ";
    }
    cout << endl;

    // Reserve test
    v3.reserve(10);
    cout << "After reserve: size = " << v3.size() << ", capacity = " << v3.capacity() << endl;

    // Insert test
    v3.insert(1, 8);
    cout << "After insert: ";
    for (unsigned i = 0; i < v3.size(); ++i) {
        cout << v3.at(i) << " ";
    }
    cout << endl;

    // Erase test
    v3.erase(1);
    cout << "After erase: ";
    for (unsigned i = 0; i < v3.size(); ++i) {
        cout << v3.at(i) << " ";
    }
    cout << endl;

    return 0;
}
