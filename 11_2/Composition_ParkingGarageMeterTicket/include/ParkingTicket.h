#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include <string>
#include <iostream>
using namespace std;

class ParkingTicket
{
    public:
        ParkingTicket(const ParkedCar &argPC, const ParkingMeter &argPM, const PoliceOfficer &argPO);
        //pass by reference ; avoids unnecessary copies or creation of temporary objects/instances.

        friend ostream& operator<<(ostream& output, ParkingTicket &object);
        string to_String() const;
        //void determineFine(const ParkingMeter &argPM);//made change around 10:30pm on 11/02
        void determineFine();

    private:
        ParkedCar aPC;
        ParkingMeter aPM;
        PoliceOfficer aPO;
        int fine, extraMinutes;

};

#endif // PARKINGTICKET_H
