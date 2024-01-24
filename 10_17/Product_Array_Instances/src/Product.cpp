#include "Product.h"

//constructor with default values for the parameters
Product::Product(int ccode, string nname, double pprice) {
  code = ccode;
  name = nname;
  price = pprice;
}

int Product::getCode() {
  return code;
}

string Product::getName() {
  return name;
}

double Product::getPrice() {
  return price;
}
