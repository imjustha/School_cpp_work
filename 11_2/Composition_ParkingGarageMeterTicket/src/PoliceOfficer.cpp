#include "PoliceOfficer.h"
#include "ParkingTicket.h" //as PoliceOfficer needs to be able to create a ParkingTicket

//CODIO SOLUTION BEGIN
PoliceOfficer::PoliceOfficer(string argName, string argBadgeNumber)
{
    //ctor
    name = argName;
    badgeNumber = argBadgeNumber;
}

//string PoliceOfficer::inspect(ParkedCar argPC, ParkingMeter argPM){  ////made change around 10:30pm on 11/02
string PoliceOfficer::inspect(const ParkedCar &argPC, const ParkingMeter &argPM){
    if(argPC.getMinutes() > argPM.getMinutes()){
        //argPC, a ParkedCar, has been staying longer than what it paid for inside
        //argPM, a ParkingMeter
        //  which means we need to issue a ticket
        //ParkingTicket::ParkingTicket(ParkedCar argPC, ParkingMeter argPM, PoliceOfficer argPO)

        ParkingTicket aPT = ParkingTicket(argPC, argPM, *this);
        //this refers to the current object's address
        // so, *this refers to the current object

        string stringPT = aPT.to_String();
        return stringPT;
    }else{
        string justCheck = "Police Officer: " + name + " with badge <" + badgeNumber + "> checked the " +
                             argPC.to_String() + " and " + argPM.to_String() + " and determined no fine is need as of yet.";
        return justCheck;
    }
}

string PoliceOfficer::to_String()const {
    return "Police Officer: " + name + " with badge <" + badgeNumber + ">";
}

ostream& operator<<(ostream& output, const PoliceOfficer &object){
    output << object.to_String();
    return output;
}

//CODIO SOLUTION END
