//FREEZE CODE BEGIN
#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

   double real, imaginary;
   cin >> real >> imaginary;

   Complex c1, c2;
   c1.setReal(real);
   c1.setImaginary(imaginary);

   cin >> c2; // >> operator overloading on Complex

   Complex c3 = c1 + c2; // operator overloading!

   cout << c3 << endl; // operator overloading!

   c2 = c3 += Complex("1.9 10.01"); //create a temporary object from a string and add it to c3
   /* Same effect as following 3 lines:
   Complex c4("1.9 10.01");
   c3 += c4;
   c2 = c3;
   */
   cout << c2 << endl;
   Complex c4 = ~c2;
   cout << c4 << endl; //~ operator should return conjugate of complex number: (a,b) --> (a,-b)

   //So far, we created objects as local variables, we can use dynamic memory too, using pointers.
   Complex *c5p = new Complex(11.11, 22.22);
   //it is common practice to use get methods are used to access private variables.
   cout << c5p->getReal() + c5p->getImaginary() << endl;
}
//FREEZE CODE END
