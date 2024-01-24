//FREEZE CODE BEGIN
#ifndef COMPLEX_H //# if not defined
#define COMPLEX_H  //define it!

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
    public:
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

    protected:

    private:
        double real, imaginary;
};

#endif // COMPLEX_H
//FREEZE CODE END
