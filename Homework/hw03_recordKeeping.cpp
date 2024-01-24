#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//CODIO SOLUTION BEGIN
string names[1000];
int counts[1000];
int numEntries=0;

string sortAndCombine(string name1, string name2, string name3) {
   //sort the strings first.
    string first, second, third;
    if (name1 < name2) {
        first = name1;
        second = name2;
    } else {
        first = name2;
        second = name1;
    }

    if (name3 < first) {
        third = second;
        second = first;
        first = name3;
    } else if (name3 < second) {
        third = second;
        second = name3;
    } else
        third = name3;

    return first + " " + second + " " + third;
}

void checkAndAdd(string name1, string name2, string name3) {

    string combinedString = sortAndCombine(name1, name2, name3);
    
    //search whether this combination already exists?
    for(int i=0; i<numEntries; i++)
        if (names[i] == combinedString) {
            counts[i]++;
            return;
        }
        
   //combination does not exist - create new one!
    names[numEntries] = combinedString;
    counts[numEntries] = 1;
    numEntries++;
}

int main()
{
    int inputLines=0;
    string s1, s2, s3;

    cin >> inputLines;
    for(int i=0; i<inputLines; i++) {
        cin >> s1 >> s2 >> s3;
        checkAndAdd(s1, s2, s3);
    }

    int maxSoFar = 0;
    for(int i=0; i<numEntries; i++) 
        if (maxSoFar < counts[i])
            maxSoFar = counts[i];

    cout << maxSoFar;
}
//CODIO SOLUTION END