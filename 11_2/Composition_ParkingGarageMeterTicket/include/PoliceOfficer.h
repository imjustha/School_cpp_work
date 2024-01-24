#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H
#include <string>
#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"

using namespace std;

class PoliceOfficer
{
    public:
        PoliceOfficer(string argName="defaultPOName", string argBadgeNum="defaultPOBadge");
        string inspect(const ParkedCar &argPC, const ParkingMeter &argPM);
        //string inspect(ParkedCar argPC, ParkingMeter argPM); //made change around 10:30pm on 11/02
        //ParkingTicket inspect(ParkedCar argPC, ParkingMeter argPM);
        string getName() const { return name; }
        string getBadgeNumber()const { return badgeNumber; }
        string to_String() const ;
        friend ostream& operator<<(ostream& output, const PoliceOfficer &object);

    private:
        string name;
        string badgeNumber;
};

#endif // POLICEOFFICER_H
