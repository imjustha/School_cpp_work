#include <iostream>

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

int main()
{
    ParkedCar car("abc1234", 17);
    ParkingMeter pm(10) ; // purchasing 10 minutes in the parking meter
    PoliceOfficer po("James Bond", "007");

    string inspectResult = po.inspect(car, pm);
    cout << inspectResult << endl;

    int uiPCmin, uiPMmin;
    string uiPClicense;
    cout << "Enter <license> <minutesParked> : ";
    cin >> uiPClicense >> uiPCmin;
    car = ParkedCar(uiPClicense, uiPCmin);
    cout << "Enter minutes purchased in the meter";
    cin >> uiPMmin;
    pm = ParkingMeter(uiPMmin);
    inspectResult = po.inspect(car, pm);
    cout << inspectResult << endl;
}
