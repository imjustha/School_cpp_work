#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;
//CODIO SOLUTION BEGIN

class Employee {
  public:
    Employee(string nname, double rate, double hhours) {
      name = nname;
      hourlyRate = rate;
      hours = hhours;
    }
    //virtual enables polymorphism
    //=0 makes this method abstract
    //& also makes the class abstract
    virtual double computePay() = 0;
    string getName() {
      return name;
    }
  protected: //accessible directly from derived classes only
    double hours, hourlyRate;
  private:
    string name;
};

//PartTimeEmployee is a type of Employee
class PartTimeEmployee : public Employee {
  public:
    PartTimeEmployee(string nname, double rate, double hours) :
      Employee(nname, rate, hours) {
      }
    double computePay() {
      return hourlyRate * min(30.0, hours);
    }
};
//FullTimeEmployee is a type of Employee
class FullTimeEmployee : public Employee {
  public:
    FullTimeEmployee(string nname, double rate) :
      Employee(nname, rate, 40) {
      }
    double computePay() {
      return 40 * hourlyRate;
    }
};

//NonExemptEmployee is a type of FullTimeEmployee
class NonExemptEmployee : public FullTimeEmployee {
  public:
    NonExemptEmployee(string nname, double hhourlyRate, double hhours):
      FullTimeEmployee(nname, hhourlyRate) {
        hours = hhours;
      }
    double computePay() {
      double pay = FullTimeEmployee::computePay(); //calling Parent class's method
      if (hours <= 40){ //no overtime
        return pay;
      }else{//overtime case
        return pay + 1.5 * hourlyRate * (hours-40);
      }
    }
};
//ShiftEmployee is a type of FullTimeEmployee
class ShiftEmployee : public FullTimeEmployee {
  public:
    ShiftEmployee(string nname, double hhourlyRate, int shiftNumber):
      FullTimeEmployee(nname, hhourlyRate) {
        shift = shiftNumber;
      }
    double computePay() {
      return FullTimeEmployee::computePay() * (1+ (shift-1) * 0.05);
      //OR you can use a switch statement or an if..else..if to do this computation
    }
  private:
    int shift;
};


//ShiftEmployee is a type of FullTimeEmployee
class SalesEmployee : public FullTimeEmployee {
  public:
    SalesEmployee(string nname, double hhourlyRate, double aactual, double ttarget) :
      FullTimeEmployee(nname, hhourlyRate) {
        actual = aactual;
        target = ttarget;
      }
    double computePay() {
    // only when target is exceeded, compute 10% commission rate and add to pay
      double pay = FullTimeEmployee::computePay(); //calling Parent class's method
      if (actual > target){ //exceeded the target?
        pay += (actual-target) * 0.10;
      }
      return pay;
    }

  private:
    double actual, target;
};
//CODIO SOLUTION END

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
