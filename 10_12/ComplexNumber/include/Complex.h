#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Complex {
  public:
    Complex(double rreal, double imag);
    //Complex(istream &input);

    Complex add(Complex second);
    void addTo(Complex second);
    double abs();
    string toString();

  private:
    double real, imaginary;  // a + ib
};


#endif // COMPLEX_H
