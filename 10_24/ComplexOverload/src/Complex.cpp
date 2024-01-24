#include "Complex.h"
/*
Complex(double rreal=0, double imag=0);
Complex(string input);

double getReal() const;
double getImaginary() const;
void setReal(double rreal);
void setImaginary(double imag);

// c = a + b;    c = a.add(b);
Complex operator+(const Complex &second) const;
// a += b;
Complex operator+=(const Complex &second);
Complex operator~() const;

friend istream& operator>>(istream& input, Complex &object);
friend ostream& operator<<(ostream& output, Complex &object);

*/

//CONSTRUCTOR
Complex::Complex(double argReal, double argImg){
    real = argReal;
    imaginary = argImg;
}
Complex::Complex(string input){
    real = 0;
    imaginary = 0;
    istringstream(input) >> real >> imaginary;
}

double Complex::getReal() const{
    return real;
 }
double Complex::getImaginary() const{
    return imaginary;
}

void Complex::setReal(double argReal) {
     real = argReal ;
 }
void Complex::setImaginary(double argImg) {
    imaginary = argImg;
}

//c = a + b;  rather than c = a.add(b);
Complex Complex::operator+(const Complex &second) const {
    return Complex(real+second.real, imaginary+second.imaginary);
}
// a += b; rather than c = a.addTo(b);
Complex Complex::operator+=(const Complex &second) {
     real += second.real;
     imaginary += second.imaginary;
}

//return conjugate
//if this is of the form (a, ib)
//result of ~(a, ib) = (a, -ib)
 Complex Complex::operator~()const {
    return Complex(real, -imaginary);
 }

istream& operator>>(istream& input, Complex &object){
    input >> object.real >> object.imaginary;
}

//instead of to_String method
ostream& operator<<(ostream& output, Complex &object){
    output << "(" << object.real << "," << object.imaginary << ")";
    return output;
}
