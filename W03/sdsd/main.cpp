#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

Rational::Rational () 
    : numerator(0), denominator(1)
{}

Rational::Rational (int i)
: numerator(i), denominator(1)
{}

Rational::Rational(int i, int j)
    : numerator(i), denominator(j)
{}

Rational Rational::add(const Rational & inp) const {
    const int & a = this->numerator;
    const int & b = this->denominator;
    const int & c = inp.numerator;
    const int & d = inp.denominator;

    return Rational((a*d + b*c), b*d);
}

Rational Rational::subtract(const Rational & inp) const {
    const int & a = this->numerator;
    const int & b = this->denominator;
    const int & c = inp.numerator;
    const int & d = inp.denominator;

    return Rational((a*d - b*c), b*d);
}

Rational Rational::multiply(const Rational & inp) const {
    const int & a = this->numerator;
    const int & b = this->denominator;
    const int & c = inp.numerator;
    const int & d = inp.denominator;

    return Rational(a*c, b*d);
}

Rational Rational::divide(const Rational & inp) const {
    const int & a = this->numerator;
    const int & b = this->denominator;
    const int & c = inp.numerator;
    const int & d = inp.denominator;

    return Rational(a*d, b*c);
}

void Rational::simplify() {
    int & a = this->numerator;
    int & b = this->denominator;

    int smallerVal = (a <= b) ? a : b;
    int greaterVal = (a >= b) ? a : b;
    int remainder;

    do {
        remainder = greaterVal % smallerVal;
        if (remainder == 0) {
            a = a / smallerVal;
            b = b / smallerVal; 
            return;
        }
        else {
            greaterVal = smallerVal;
            smallerVal = remainder;
        }
        

    } while (remainder != 0);

    a = a / remainder;
    b = b / remainder;
}

void Rational::display () const {
    cout << this->numerator << "/" << this->denominator;
}

Rational getRational() {};
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

