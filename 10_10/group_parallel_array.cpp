#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numPeople = 0;
//pointers to dynamically created parallel arrays 
//these are used for storing multiple values
// that are read from the file 
int *ages;
string *firstNames, *lastNames;
double *incomes;

//return the index of smallest item in ages[startIndex .. numPeople-1]
int findSmallest(int startIndex) {
    //assume the first one is the smallest and check against the remaining array items
    int smallestValue = ages[startIndex];
    int smallestIndex = startIndex;

    for(int i=smallestIndex+1 ; i<numPeople; i++)
        // check whether ages[i] is smaller. If so, update ...
        if (ages[i] < smallestValue) {
            smallestValue = ages[i];
            smallestIndex = i;
        }

    return smallestIndex;
}

void selectionSort() {
    for(int i=0; i<numPeople ; i++) {
        //find the smallest item in ages[i .. numPeople-1]
        //and swap with the ith item
        int smallestIndex = findSmallest(i);
        // swap(ages[i], ages[smallestIndex]); requires <algorithm>
        int temp = ages[smallestIndex];
        ages[smallestIndex] = ages[i];
        ages[i] = temp;

        string tempName = firstNames[smallestIndex];
        firstNames[smallestIndex] = firstNames[i];
        firstNames[i] = tempName;

        tempName = lastNames[smallestIndex];
        lastNames[smallestIndex] = lastNames[i];
        lastNames[i] = tempName;

        double tempValue = incomes[smallestIndex];
        incomes[smallestIndex] = incomes[i];
        incomes[i] = tempValue;
    }
}

int main() {
    //open the input file and read the data into arrays
    ifstream finput("group.txt");
    finput >> numPeople;

    //allocate the arrays
    ages = new int [numPeople];
    firstNames = new string [numPeople];
    lastNames = new string [numPeople];
    incomes = new double [numPeople];
    for(int i=0; i<numPeople; i++)
        finput >> ages[i] >> firstNames[i] >> lastNames[i] >> incomes[i];
    finput.close();

    cout << "From file and Before sorting:\n";
    for(int i=0; i<numPeople; i++)
        cout << ages[i] << " " << firstNames[i] << " " << lastNames[i] << " " << incomes[i] << endl;

    //sort the data by age
    selectionSort();

    cout << "After sorting:\n";
    //output the data in sorted order
    for(int i=0; i<numPeople; i++)
        cout << ages[i] << " " << firstNames[i] << " " << lastNames[i] << " " << incomes[i] << endl;
}
