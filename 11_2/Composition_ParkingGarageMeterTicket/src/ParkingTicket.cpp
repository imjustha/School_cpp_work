#include "ParkingTicket.h"

//CODIO SOLUTION BEGIN
ParkingTicket::ParkingTicket(const ParkedCar &argPC, const ParkingMeter &argPM, const PoliceOfficer &argPO)
{
    //ctor
    aPC = argPC;
    aPM = argPM;
    aPO = argPO;
    //determineFine(argPM);
    determineFine();//made change around 10:30pm on 11/02
}

//void ParkingTicket::determineFine(const ParkingMeter &argPM){//made change around 10:30pm on 11/02
void ParkingTicket::determineFine(){
    fine = 0;
    int extra = aPC.getMinutes() - aPM.getMinutes();
    if(extra > 0){
        fine = 25; //first hours charge
        extra -=60; //now that we charged, take out the first hour out of consideration
        while(extra > 0){ //any extra hour or part of
            fine += 10; //charge increases by 10
            extra -= 60; //as we charged, take out one hour out
        }
    }
    extraMinutes = aPC.getMinutes() - aPM.getMinutes() ;
}
string ParkingTicket::to_String()  const{
    return " A $" + to_string(fine) + " issued to the " + aPC.to_String() +
    " as it has been parked for < " + to_string(extraMinutes) +
    " > minutes extra...Signed by " + aPO.to_String() ;

}
ostream& operator<<(ostream& output, ParkingTicket &object){
    output << object.to_String();
    return output;
}

//CODIO SOLUTION END
