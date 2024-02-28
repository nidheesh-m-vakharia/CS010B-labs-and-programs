#include "IntVector.h"
#include <iostream>
#include <stdexcept>

IntVector::IntVector()
    : _size(0), _capacity(0), _data(nullptr)
{}

IntVector::IntVector(unsigned capacity)
    : _size(0), _capacity(0), _data(nullptr)
{   
    _capacity = capacity;
    _size = capacity;
    if (_capacity != 0) {
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = 0;
        }
    }
}

IntVector::IntVector(unsigned capacity = 0 , int value = 0)
    : _size(0), _capacity(0), _data(nullptr)
{   
    _capacity = capacity;
    _size = capacity;
    if (_capacity != 0) {
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
}

IntVector::~IntVector(){
    delete[] _data;
};

unsigned IntVector::size() const { return _size; }

unsigned IntVector::capacity() const { return _capacity; }

bool IntVector::empty() const { return _data == nullptr; }

const int & IntVector::at(unsigned index) const {
    if (_data == nullptr || index >= _size || index < 0) {
        throw std::out_of_range("IntVector::at_range_check");
    }

    return _data[index];
}   

const int & IntVector::front() const { 
    if (_data == nullptr) {

        throw std::out_of_range("IntVector::front() doent exist");
    }
    return _data[0];

}

const int & IntVector::back() const { 
    if (_data == nullptr) {
        throw std::out_of_range("IntVector::back() doent exist");
    }
    return _data[_size - 1]; 
}