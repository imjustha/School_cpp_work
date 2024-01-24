#include "MenuItem.h"

//CODIO SOLUTION BEGIN
MenuItem::MenuItem(string ccode, string nname, double pprice)
{
    code = ccode;
    name = nname;
    price = pprice;
}

string MenuItem::getCode() {
    return code;
}
string MenuItem::getName() {
    return name;
}

double MenuItem::getPrice() {
    return price;
}
//CODIO SOLUTION END
