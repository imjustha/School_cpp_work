#include <iostream>
#include <string>
using namespace std;

int main(){
    string line;

    while (getline(cin, line)){
        int maxValue = -2147483648; // Minimum possible 32-bit integer value

        int num = 0;
        bool isNum = false;

        for (char c : line){
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                isNum = true;
            } else{
                if (isNum) {
                    if (num > maxValue) {
                        maxValue = num;
                    }
                    num = 0;
                    isNum = false;
                }
            }
        }
        
        if (isNum && num > maxValue){
            maxValue = num;
        }

        cout << "Max value in line: ";
        if (maxValue != -2147483648){
            cout << maxValue;
        } else {
            cout << "No valid numbers";
            cin.clear(); // Clear error from the bad input
        }
        cout << endl;
    }
    return 0;
}