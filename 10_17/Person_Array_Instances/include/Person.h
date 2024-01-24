#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
    public:
        Person(int argAge=0, string argFName = "", string argLName = "", double argSalary=0);
        int getAge();
        string getName();
        double getIncome();

    private:
        int age;
        string firstName, lastName;
        double income;
};

#endif // PERSON_H
