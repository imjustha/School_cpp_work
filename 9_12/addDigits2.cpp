#include <iostream>
#include <string>
using namespace std;

int main(){
    //get a number as string & add the digits
    //"123" - '1' '2' '3'
    //get numberical value and add them together

    string ui;
    cin >> ui;
    int total = 0;

    for(int i=0; i<ui.length(); i++){
        total += ui.at(i) - '0' ; //get the numerical value
        //a couple of more ideas:
        //parsing and getting int value
        //typecast
    }
    cout << total << endl;
}