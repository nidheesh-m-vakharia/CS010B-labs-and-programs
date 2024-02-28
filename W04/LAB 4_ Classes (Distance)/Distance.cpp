#include "Distance.h"
using namespace std;

//Corrects the object
void Distance::init(){

    // if feet is less than zero
     if (_feet < 0) {
        _feet *= -1;
    }
    // if inches is less than zero
    if (_inches < 0) {
        _inches *= -1;
    }

    while (_inches >= 12.0) {
        ++_feet;
        _inches -= 12.0;
    }
}

// -------------------------CONSTRUCTORS---------------------------
//()
Distance::Distance()
    : _feet(0), _inches(0)
{
}

//(unsigned, double)
Distance::Distance(unsigned ft, double in)
    : _feet(ft), _inches(in)
{
    init();
}

//(double)
Distance::Distance(double ft)
    :_feet(0), _inches(ft)
{
    init();
}

//--------------------------ACCESORS---------------------------------

unsigned Distance::getFeet() const {return (_feet);}

double Distance::getInches() const {return (_inches);}

double Distance::distanceInInches() const {return (_inches + ((double)_feet)*12);}

double Distance::distanceInFeet() const {return (_inches/12.0 + (double)_feet);}

double Distance::distanceInMeters() const {return (distanceInInches() * 0.0254); }

Distance Distance::operator+ (const Distance& rhs) const {

    double temp_inches = _inches + rhs._inches;
    unsigned temp_feet = _feet + rhs._feet;

    return Distance(temp_feet, temp_inches);
}

Distance Distance::operator-(const Distance &rhs) const {
    unsigned temp_feet;
    double temp_inches;

    if (_feet <= rhs._feet) {
        temp_feet = rhs._feet - _feet;
        temp_inches = rhs._inches - _inches;
    }

    else{
        temp_feet = _feet - rhs._feet;
        temp_inches = _inches - rhs._inches;
    }

    while (temp_inches < 0 )
    {   
        --temp_feet;
        temp_inches = 12 + temp_inches;
    }
    


    return Distance(temp_feet, temp_inches);
}

ostream & operator<<(std::ostream &out, const Distance &rhs) {
    out << rhs._feet << "\' " << rhs._inches << "\"";
    return out;
}
