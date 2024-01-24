#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numPeople = 0;

struct Person{
    int age;
    string firstName, lastName;
    double income;
};

//int *allNumbers;
Person *persons; //pointer for dynamic memory allocation
//Person persons[1000]; //static memory allocation

//return the index of smallest item in ages[startIndex .. numPeople-1]
int findSmallest(int startIndex) {
    //assume the first one is the smallest and check against the remaining array items
    int smallestValue = persons[startIndex].age;
    int smallestIndex = startIndex;

    for(int i=smallestIndex+1 ; i<numPeople; i++)
        // check whether ages[i] is smaller. If so, update ...
        if (persons[i].age < smallestValue) {
            smallestValue = persons[i].age;
            smallestIndex = i;
        }

    return smallestIndex;
}

void selectionSort() {
    for(int i=0; i<numPeople ; i++) {
        //find the smallest item in persons[i .. numPeople-1]
        //and swap with the i-th item
        int smallestIndex = findSmallest(i);
        Person temp = persons[smallestIndex];
        persons[smallestIndex] = persons[i];
        persons[i] = temp;

    }
}
int main(){
    //open the input file and read the data into arrays
    ifstream finput("group.txt");
    finput >> numPeople;

//    Person p1 ;
//    p1.age = 45;
//    p1.firstName = "Abe";
//    p1.lastName = "Lincoln";
//    p1.income = 100000;
//    Person p2 = {34, "John", "Doe 1", 123456};

    //allNumbers = new int[10000];
    //replace several parallel arrays with one array of struct person
    persons = new Person[numPeople];
    for(int i=0; i<numPeople; i++){
        finput >> persons[i].age >> persons[i].firstName
            >> persons[i].lastName >> persons[i].income;
    }
    finput.close();

    //print before sorrting
    cout << " Before sorting" << endl;
    for(int i=0; i<numPeople; i++){
        cout << persons[i].age << " " << persons[i].firstName << " "
            << persons[i].lastName << "  " << persons[i].income << endl;
    }

    selectionSort();
    cout << " After sorting" << endl;
    for(int i=0; i<numPeople; i++){
        cout << persons[i].age << " " << persons[i].firstName << " "
            << persons[i].lastName << "  " << persons[i].income << endl;
    }


}


