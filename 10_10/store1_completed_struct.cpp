#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAXPRODUCTS = 1000;

//declare the struct
struct Product{
    int code;
    string name;
    double price;
};

Product products[MAXPRODUCTS]; //an array of structs
int numProducts = 0;

//read from file and put the info into the array of structs
void setup(){
    ifstream finput("products.txt");
    finput >> numProducts;  //get # of products first

    //get product codes, names & prices
    for(int i=0; i<numProducts; i++){
        finput >> products[i].code >> products[i].name >> products[i].price;
    }
}

//goal is to list all the products
void listProducts(){
    cout << "Available products : \n";
    for(int i=0; i<numProducts; i++){
            cout << products[i].code << " : " << products[i].name << " @ " << products[i].price << "per pound.\n";
    }
}

//simple linear search
// returns the index of the product with the specified PLU Code
// returns -1 if that code is not found
int findIndex(int inputCode){
    for(int i=0; i<numProducts; i++){
        if(inputCode == products[i].code){
            return i;
        }
    }
    //control comes here ONLY when inputCode is not found in the array
    return -1;
}

//gets the user's choice
// 0 : if user wants to finish up
// plu code : if user chooses to continue purchase
int getUserSelection(){
    int plu, selection = 0;
    while(true){
        listProducts();
        cout << "Enter PLU(0 to end) : ";
        cin >> plu;
        if(plu == 0){
            return -1;
        }
        selection = findIndex(plu);
        if(selection >=0){
            //item has been found
            return selection;
        }
        cout << "Invalid Selection.\n";
    }
}
//check out functionality for one customer
//returns the total amount
double checkout(){
    double total = 0, weight=0;
    cout <<fixed << setprecision(2);
    while(true){
        int selection = getUserSelection();
        if(selection < 0){
            //user indicated they are done
            break;
        }
        cout << "Enter weight for " << products[selection].name << " : ";
        cin >> weight;

        total += weight * products[selection].price;

        cout << "Total so far: $" << total << endl;
    }
    cout << "Final total: $" << total << endl;
    return total;
}

int main(){
    double grandTotal = 0;
    char response = 'n';

    setup();

    while (response == 'n')
    {
        grandTotal += checkout();
        cout << "(n)ext customer OR (c)lose the register? ";
        cin >> response;
    }

    cout << "Grand total: $" << grandTotal << endl;

    return 0;
}
