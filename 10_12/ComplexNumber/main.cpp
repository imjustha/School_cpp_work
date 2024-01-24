#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

   double real, imaginary;
   cin >> real >> imaginary;
   Complex c1 (real, imaginary); //constructor #1

   cout << "Enter 2 complex number's real & imaginary parts :";
   cin >> real >> imaginary;
   Complex c2 (real, imaginary); //constructor #1

   Complex c3 = c1.add(c2); //c1 + c2

   cout << c3.toString() << endl; //cout << c3;

   c3.addTo(c2); //c3 += c2;
   cout << c3.toString() << endl;

   cout << c3.abs() << endl;  // absolute value of complex number
}
