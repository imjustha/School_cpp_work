#include <iostream>
using namespace std;

int main(){
    //using pointers
    char name[] = "Lincoln";
    char *namep = &name[0];
    int n = sizeof(name)/sizeof(char);
    char *endp = namep +  n;

    //print all even chars inside name
    while(namep < endp){
        cout << *namep ;
        namep += 2;
    }
    cout << endl;
    //print all odd chars inside name
    namep = &name[1];
    while(namep < endp){
        cout << *namep ;
        namep += 2;
    }

}