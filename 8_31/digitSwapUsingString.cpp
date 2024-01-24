#include <iostream>
#include <string>
using namespace std;

int main(){
    string number;
    cin >> number;

    cout << "Before swap : " << number.at(0) << number.at(1) << endl;
    cout << "After swap : " << number.at(1) << number.at(0) << endl;
}