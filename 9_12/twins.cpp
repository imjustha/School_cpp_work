#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
    string names[] = { "Emma", "Julie", "Tiffany", "Lucy", "Angie",
                        "Jackie", "Jill", "Lia", "Melody", "Karen" };

    srand(time(NULL));  //# of seconds from Jan 1 1970
    string child1 = names [rand() % 10];
    string child2 = names [rand() % 10];
    while(child1 == child2){
            //cout << child2 << endl;
        child2 = names [rand() % 10];
    }
    cout << "Names for twins : " << child1 << " " << child2 << endl;
}