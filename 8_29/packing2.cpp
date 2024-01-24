#include <iostream>
using namespace std;

int main(){
    int capacity;
    int total = 0;
    int item;

    cin >> capacity;
    while(true){
        cin >> item;
        //is it possible to include in current box?
        if(total + item <= capacity){
            total += item;
        }else{
            cout << "total = " << total << endl; //output current box
            total = item; //start a new box with the current item
        }
    }
}