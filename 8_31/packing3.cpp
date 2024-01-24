#include <iostream>
using namespace std;

int main() {
    int items1, items2, items3;

    cout << "Enter # of 1 lbs : ";
    cin >> items1;
    cout << "Enter # of 2 lbs : ";
    cin >> items2;
    cout << "Enter # of 3 lbs : ";
    cin >> items3;

    int boxes = items2 + items3;

    if (items1 > items2){
        int excess1lb = items1 - items2;
        boxes += excess1lb / 3;
        if (excess1lb % 3 > 0){
            boxes ++;
        }
    }
    cout << "Total # of boxes needed : " << boxes << endl;
}