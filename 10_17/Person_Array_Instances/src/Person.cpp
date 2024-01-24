#include "Person.h"
using namespace std;
/*
Person(int argAge=0, string argFName = "", string argLName = "", double argSalary=0);
int getAge();
string getName();
double getIncome();

int age;
string firstName, lastName;
double income;

*/
//Person::Person(int argAge=0, string argFName = "", string argLName = "", double argSalary=0)
Person::Person(int argAge, string argFName, string argLName, double argSalary)
{
    //ctor
    age = argAge;
    firstName = argFName;
    lastName = argLName;
    income = argSalary;
}
//getAge() is a method that returns an int
//it is defined inside Person class
int Person::getAge(){
    return age;
}

string Person::getName(){
    return firstName + " " + lastName;
}

double Person::getIncome(){
    return income;
}
