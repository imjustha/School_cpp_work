#ifndef CELLPHONE_H
#define CELLPHONE_H
#include <string>
using namespace std;


class CellPhone
{
    public:


        CellPhone(string argModel, string argPhoneNumber, string argColor);    //constructor
        string getColor();
        void setColor(string argColor);
        string toString();

    private:
        string model;
        string phoneNumber;
        string color; //try moving this line under public and then in main.cpp, uncomment the line #25

};

#endif // CELLPHONE_H
