#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

    int x[4] = {10, 20, 30, 40};
    int y[4];

    int *xp = x;
    int *yp = &y[3]; 
    for(int i=0; i<4; i++){
        *yp-- = *xp++;
    }
    for(int i=0; i<4; i++) {
        cout << y[i] << " ";
    }
    return 0;
}