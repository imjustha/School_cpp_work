
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;
// WRITE YOUR CODE HERE

//base class, parent class, super class <-- generic
//derived class, child class, sub class <-- specific

int main() {
  Employee *employees[1000];
  int numEmployees=0;
  string code, firstName, lastName, name;
  double hourlyRate, hours, actual, target;
  int shiftNumber;

  while(true) {
    cin >> code;
    if (code == "end")
      break;
    cin >> firstName >> lastName;
    name = firstName + " " + lastName;
    if (code == "PT") {
      cin >> hourlyRate >> hours;
      employees[numEmployees++] = new PartTimeEmployee(name, hourlyRate, hours);
    }
    else if (code == "FT") {
      cin >> hourlyRate;
      employees[numEmployees++] = new FullTimeEmployee(name, hourlyRate);
    }
    else if (code == "NE") {
      cin >> hourlyRate >> hours;
      employees[numEmployees++] = new NonExemptEmployee(name, hourlyRate, hours);
    }
    else if (code == "TE") {
      cin >> hourlyRate >> shiftNumber;
      employees[numEmployees++] = new ShiftEmployee(name, hourlyRate, shiftNumber);
    }
    else if (code == "SE") {
      cin >> hourlyRate >> actual >> target;
      employees[numEmployees++] = new SalesEmployee(name, hourlyRate, actual, target);  
    }
  }
  cout << "Weekly pay for " << numEmployees << " employees:\n";
  for(int i=0; i<numEmployees; i++)
    cout << employees[i]->getName() << " $" 
      << fixed << setprecision(2) << employees[i]->computePay() << endl;
}