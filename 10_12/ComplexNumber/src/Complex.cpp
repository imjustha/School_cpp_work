#include "Complex.h"
#include <string>

Complex::Complex(double rreal, double imag) {
  real = rreal;
  imaginary = imag;
}

//we are implementing a method add that is defined in Class Complex (defined inside the Complex.h)
//add method returns an instance of Class Complex - this is the first term you see in the next line
Complex Complex::add(Complex second) {
  // (real, imaginary) + (second.real, second.imaginary)
  return Complex(real+second.real,
                imaginary+second.imaginary);
}

//we are implementing a method addTo that is defined in Class Complex (defined inside the Complex.h)
//addTo method does not return anything - this is the first term you see in the next line
//add second object to current object!
void Complex::addTo(Complex second) {
  real += second.real;
  imaginary += second.imaginary;
}

double Complex::abs() {
  return sqrt(real*real + imaginary*imaginary);
}

string Complex::toString() {
    string result = '(' + to_string(real) + "," + to_string(imaginary) + ")";
    return result;
    //in order for the output to match with Codio, you can use the following
  //ostringstream ostr;
  //ostr << '(' << real << "," << imaginary << ')';
  //return ostr.str();
}
