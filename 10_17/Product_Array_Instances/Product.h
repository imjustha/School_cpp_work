#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <iomanip> // input/output manipulation
#include <string>
#include <fstream>

using namespace std;

class Product {
  public:
    //constructor method
    Product(int ccode=0, string nname="", double pprice=0);
    //get methods
    int getCode();
    string getName();
    double getPrice();

  private:
    int code;
    string name;
    double price;
};

#endif // PRODUCT_H
