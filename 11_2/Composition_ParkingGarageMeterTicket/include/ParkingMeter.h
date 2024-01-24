#ifndef PARKINGMETER_H
#define PARKINGMETER_H
#include <string>
#include <iostream>
using namespace std;

class ParkingMeter
{
    public:
        ParkingMeter(int argMinutes=0);
        int getMinutes() const { return minutes; }
        void setMinutes(int val=0) ;
        string to_String()  const;
        friend ostream& operator<<(ostream& output, const ParkingMeter &object);

    private:
        int minutes;
};

#endif // PARKINGMETER_H
