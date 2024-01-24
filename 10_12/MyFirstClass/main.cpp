#include <iostream>
#include <string>
#include "CellPhone.h"

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
//    return 0;
//creating an instance of CellPhone Class called phone1 by calling the constructor
    CellPhone phone1 = CellPhone("Apple", "123-345-6789", "red");
    CellPhone phone2 = CellPhone("Samsung", "234-567-8910", "rose gold");

    cout << phone1.toString() << endl;
    cout << phone2.toString() << endl;

    int ui;
    cout << "Change color of phone 1 / 2 ?";
    cin >> ui;

    string uiColor;
    cin >> uiColor;

    //phone1.color = "green"; //NOT POSSIBLE as color is private

    if(ui == 1){
        phone1.setColor(uiColor);
    }else{
        phone2.setColor(uiColor);
    }

    cout << " After change of color\n";

    cout << phone1.toString() << endl;
    cout << phone2.toString() << endl;
}
