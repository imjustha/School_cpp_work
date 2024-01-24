#ifndef PARKEDCAR_H
#define PARKEDCAR_H
#include <string>
#include <iostream>
using namespace std;

class ParkedCar
{
    public:
        ParkedCar(string argLicense="default", int argMinutes=0);
        int getMinutes() const  { return minutes; }
        void setMinutes(int val=0);
        string to_String() const;
        friend ostream& operator<<(ostream& output, const ParkedCar &object);

    private:
        string license;
        int minutes;
};

#endif // PARKEDCAR_H
