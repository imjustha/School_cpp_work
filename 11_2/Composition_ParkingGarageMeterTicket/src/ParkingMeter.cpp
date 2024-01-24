#include "ParkingMeter.h"
//CODIO SOLUTION BEGIN

ParkingMeter::ParkingMeter(int argMinutes)
{
    //ctor
    minutes = argMinutes;
}
void ParkingMeter::setMinutes(int val) {
    if(val < 0){
        minutes = 0;
    }else{
        minutes = val;
    }
}
string ParkingMeter::to_String()  const{
    return " Parking meter set for < " + to_string(minutes) + " > minutes";
}
ostream& operator<<(ostream& output, const ParkingMeter &object){
    //output << " Parking meter set for < " << object.minutes << object.minutes << " > minutes";
    output << object.to_String();
    return output;
}
//CODIO SOLUTION END
