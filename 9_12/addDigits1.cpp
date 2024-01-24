#include <iostream>
#include <string>
using namespace std;

int main(){
    //get a number and add its's digits
    //123--> %10, get 3, add 3 to the total and then divisde by 10 to get 12
    //12 --> %10 get 2, add 2 to the total and then divide by 10 to get 1

    int number;
    int total = 0;
    cin >> number;
    while(number > 0){
        total += number%10; //get the least significant digit
        number /= 10; // move to the upper part
    }
    cout << total << endl;
}