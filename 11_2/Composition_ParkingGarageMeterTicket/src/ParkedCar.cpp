#include "ParkedCar.h"
#include <string>
#include <iostream>

//CODIO SOLUTION BEGIN
ParkedCar::ParkedCar(string argLicense, int argMinutes)
{
    //ctor
    license = argLicense;
    minutes = argMinutes;
}
void ParkedCar::setMinutes(int val) {
    if(val < 0){
        minutes = 0;
    }else{
        minutes = val;
    }
}
string ParkedCar::to_String() const{
    return " Car <" + license +  "> parked for < " + to_string(minutes) + " > minutes";
}

ostream& operator<<(ostream& output, const ParkedCar &object){
    //output << " Car <" << object.license << "> parked for " << object.minutes << " minutes";
    output << object.to_String();
    return output;
}
//CODIO SOLUTION END
