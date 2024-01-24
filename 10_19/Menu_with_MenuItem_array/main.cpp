#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
   Menu menu("menu.txt");

   string uiOrder;
   getline(cin, uiOrder); //as we expect codes to be separated by space

   menu.process(uiOrder);

}
