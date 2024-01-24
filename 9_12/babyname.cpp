#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
    string names[] = { "Emma", "Julie", "Tiffany", "Lucy", "Angie",
                        "Jackie", "Jill", "Lia", "Melody", "Karen" };

    srand(time(NULL));  //# of seconds from Jan 1 1970
    cout << names [rand() % 10] << endl;
}