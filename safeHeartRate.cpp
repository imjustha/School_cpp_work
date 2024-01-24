#include <iostream>
using namespace std;


int main () {
    
    int age, heartrate;

    cout << "Input your age: ";
    cin >> age;

    heartrate = 220 - age;
    cout << "your heart rate is " << heartrate << endl;
    
    return 0;
}