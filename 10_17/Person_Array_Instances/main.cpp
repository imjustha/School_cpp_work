#include <iostream>
#include "Person.h"
#include <fstream>
using namespace std;

//here, priya as well as p1 are 2 objects/instances of Person class
//Person priya;
//Person p1;

//Pointer to one or more Person objects/instances
Person *persons;
int numPeople; //global to store the number of people read from file

int findSmallest(int startIndex){
    //calling the getter to get info regarding the age
    int smallestValue = persons[startIndex].getAge();
    int smallestIndex = startIndex;

    for(int i=startIndex+1; i<numPeople; i++){
        if(persons[i].getAge() < smallestValue){
            smallestValue = persons[i].getAge();
            smallestIndex = i;
        }
    }
    return smallestIndex;
}


void selectionSort(){
    for(int i=0; i<numPeople; i++){
        //find smallest item in age & swap with i-th item
        int smallestIndex = findSmallest(i);

        //swap with a temp Person instance/object
        Person temp = persons[smallestIndex];
        persons[smallestIndex] = persons[i];
        persons[i] = temp;

    }
}

int main()
{
//    cout << "Hello world!" << endl;
//    return 0;
    //open group.txt and read data
    ifstream finput("group.txt");
    finput >> numPeople;

    //now the pointer persons is pointing to a dynamic array of
    //  numPeople Person objects/instances
    //  how dynamic ? because keyword new is used
    persons = new Person[numPeople];

    for(int i=0; i<numPeople; i++){
        int age=0;
        string fName="", lName="";
        double income=0;
        //read from file into temp variables
        finput >> age >> fName >> lName >> income;

        //use the temp variables to send as parameters/argument into the
        //  constructor for Person class
        persons[i] = Person(age, fName, lName, income);
    }
    finput.close();

    cout << "Before sorting" << endl;
    for(int i=0; i<numPeople; i++){
        cout << persons[i].getAge() << " " << persons[i].getName()
                << " " << persons[i].getIncome() << endl;
    }

    //sort data by age
    selectionSort();

    cout << "\nAfter sorting" << endl;
    for(int i=0; i<numPeople; i++){
        cout << persons[i].getAge() << " " << persons[i].getName()
                << " " << persons[i].getIncome() << endl;
    }
}//end of main
