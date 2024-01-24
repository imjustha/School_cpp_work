#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    int unitsValue = num % 10; //used modulo operator to find reminder
    int tensValue = num / 10;   //used / to divide to find quotient

    cout << "Units :" << unitsValue << endl;
    cout << "Tens :" << tensValue << endl;

    cout << "After swap : " << unitsValue * 10 + tensValue;
}