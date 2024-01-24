#include "CellPhone.h"

CellPhone::CellPhone(string argModel, string argPhoneNumber, string argColor)
{
    //ctor
    model = argModel;
    phoneNumber = argPhoneNumber;
    color = argColor;
}

string CellPhone::getColor(){
    return color;
}

void CellPhone::setColor(string argColor){
    color = argColor;
}

//gives the status of the attributes
string CellPhone::toString(){
    return "this is a " + model + " and the color is " + color + " and the number is " + phoneNumber;
}
