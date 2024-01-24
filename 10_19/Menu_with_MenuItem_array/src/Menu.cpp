#include "Menu.h"
#include <fstream>
#include <sstream>
#include <iomanip>

//CODIO SOLUTION BEGIN
Menu::Menu(string filename)
{
    //open data file & read the menu items
    //finput is of datatype ifstream and it is opening the filename
    ifstream finput(filename);
    string code, name;
    double price;

    //first, let us find out how many items are there!
    //as the first line of the file does not have that info,
    //  we are maintaining a counter & updating it as
    //  we are reading the lines just to get to the end.
    numItems = 0;
    while (finput >> code >> name >> price)
        numItems++;
    finput.close();

    //now that we have that numItems, we can
    //  dynamically allocate and point to the array of MenuItem objects
    items = new MenuItem [numItems];
    //items is declared inside Menu.h
    //line 11 declared finput to be ifstream
    //now, we are reopening it ; hence the different syntax
    //we read each line from menu.txt and put info inside temp variables
    //  and then use those to call constructor to create the MenuItem object
    //  and store it in appropriate position in the array
    finput = ifstream(filename);
    for(int i=0; i<numItems; i++) {
        finput >> code >> name >> price;
        items[i] = MenuItem(code, name, price);
    }
    finput.close();
}

//search for specific code & return MenuItem pointer
//if code is not found, return NULL
MenuItem* Menu::find(string code) {
    for(int i=0; i<numItems; i++)
        if (code == items[i].getCode())
            return &items[i];  // same as items+i; //because items is a pointer
    return NULL;
}

void Menu::process(string order) { //prompt the order string
    string code;
    istringstream orderStream(order);

    double total=0;
    cout << fixed << setprecision(2);
    while (orderStream >> code) {
            MenuItem *itemp = find(code);
            if (itemp) { //valid?
                // we are using the dereferencing operator ->
                //as itemp is a pointer to a MenuItem instance
                //if, itemp was an instance of MenuItem,
                //  then we would write it as itemp.getPrice()
                total += itemp->getPrice();
                cout << itemp->getName() << ":  $" << itemp->getPrice() << endl;
            } else
                cout << code << "is invalid. Skipping it.\n";
    }
    cout << "Total: $" << total << endl;
}
//CODIO SOLUTION END
