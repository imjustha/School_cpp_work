#include <iostream>
using namespace std;

int main(){
    int capacity;
    int total = 0;
    int ui;

    cin >> capacity;
    while(total < capacity){
        cin >> ui;
        total += ui;
    }
    total -= ui;
    cout << "Limit reached... Total " << total << endl;
}