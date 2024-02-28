#include "IntVector.h"
#include <iostream>
#include <stdexcept>

IntVector::IntVector()
    : _size(0), _capacity(0), _data(nullptr), _defaultVal(0)
{}

IntVector::IntVector(unsigned capacity)
    : _size(0), _capacity(0), _data(nullptr), _defaultVal(0)
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
    : _size(0), _capacity(0), _data(nullptr), _defaultVal(value)
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

int & IntVector::at(unsigned index) {
    if (_data == nullptr || index >= _size || index < 0) {
        throw std::out_of_range("IntVector::at_range_check");
    }

    return _data[index];
}

void IntVector::expand() {
    if (_capacity == 0) {
        ++_capacity;
    }

    else {
        _capacity *= 2;
    }

    int* newLoc = new int[_capacity];
    for (unsigned i = 0; i < _capacity; ++i) {
        newLoc[i] = _defaultVal;
    }

    for (unsigned i = 0; i < _size; i++)
    {
        newLoc[i] = _data[i];
    }

    delete[] _data;
    _data = newLoc;
    newLoc = nullptr;
}

void IntVector::expand(unsigned amount) {
    _capacity += amount;

    int* newLoc = new int[_capacity];
    for (unsigned i = 0; i < _capacity; ++i) {
        newLoc[i] = _defaultVal;
    }

    for (unsigned i = 0; i < _size; i++)
    {
        newLoc[i] = _data[i];
    }

    delete[] _data;
    _data = newLoc;
    newLoc = nullptr;

}

const int & IntVector::front() const { 
    if (_data == nullptr) {

        throw std::out_of_range("IntVector::front() doent exist");
    }
    return _data[0];

}

int & IntVector::front() { 
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

int & IntVector::back() { 
    if (_data == nullptr) {
        throw std::out_of_range("IntVector::back() doent exist");
    }
    return _data[_size - 1]; 
}

void IntVector::assign(unsigned n, int value) {
    if (_capacity  < n) {
        if (n > _capacity*2) 
            this->expand(n - _capacity);
        else
            this->expand();
    }

    for (unsigned i = 0; i < n; ++i) {
        _data[i] = value;
    }

    _size = n;
}

void IntVector::insert(unsigned index, int value) {
    if (index >= _size || index < 0) {
        throw std::out_of_range("IntVector::insert_range_check");
    }
    
    if (_size + 1 > _capacity) {
        this->expand();
    }

    ++_size;

    for (unsigned i = _size - 1; i > index; --i) {
        _data[i] = _data[i-1];
    }

    _data[index] = value;
}

void IntVector::erase(unsigned index) {
    if (_size - 1 < 0) {
        throw std::out_of_range("IntVector::erase_range_check");
    }
    if (index >= _size) {
        throw std::out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size; i++) {
        _data[i] = _data[i+1];
    }

    --_size;
}

void IntVector::push_back(int value) {
    if (_size + 1 > _capacity) {
        this->expand();
    }

    ++_size;
    _data[_size - 1] = value;
}

void IntVector::pop_back() {
    --_size;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned n, int value) {

    if (_capacity  < n) {
        if (n > _capacity*2) 
            this->expand(n - _capacity);
        else
            this->expand();
    }

    if (n > _size) {
        for (unsigned i = _size; i < n; ++i) {
            _data[i] = value;
        }
    }

    _size = n;
}

void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        this->expand(n - _capacity);
    }
}


