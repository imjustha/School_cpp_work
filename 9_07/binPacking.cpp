// #include <iostream>
// #include <sstream>
// #include <string>

// using namespace std;

// //let us assume we won't go over 100 numbers
// const int MAXITEMS = 100;
// int items[MAXITEMS], binAssignments[MAXITEMS];
// int numItems=0; //stores actual # of items
// const int BINCAPACITY = 100;

// void validate() {
    
// }

// int main() {
//    string line;
//    int numAssignments = 0;

//    //get all the items first.
//    getline(cin, line);  //get one line of input
//    istringstream istr(line);  //convert it to inputstringstream
//    //extract the numbers from the stream into the array
//    while (istr >> items[numItems]) 
//       numItems++;

//     //get bin assignments now.
//    getline(cin, line);
//    istringstream istr2(line);
//    while (istr2 >> binAssignments[numAssignments])
//       numAssignments++;

//     if (numItems != numAssignments) {
//         cout << "# of items and # of bin assignments mismatch.";
//         exit(1);
//     }
//     validate();
// }
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//let us assume we won't go over 100 numbers
const int MAXITEMS = 100;
int items[MAXITEMS], binAssignments[MAXITEMS];
int numItems=0; //stores actual # of items
const int BINCAPACITY = 100;

void validate() {
// WRITE YOUR CODE HERE
//Input item ... out of range
   //loop through items[] array and check whether any item is >100.
   for(int i=0; i<numItems; i++)
      if (items[i] > BINCAPACITY) {
         cout << "Input item " << items[i] << " out of range\n"; //item is too large
         return;
      }


   //Bin .. out of range -- inspect bin assignments - is any of them >= numItems?
   for(int i=0; i<numItems; i++)
      if (binAssignments[i] >= numItems) {
         cout << "Bin " << binAssignments[i] << " out of range\n";
         return;
      }


   //using the bin assignments, compute total for each bin
   int bins[MAXITEMS];
   //initialize the array
   for(int i=0; i<numItems; i++)
      bins[i] = 0;
   for(int i=0; i<numItems; i++)
      // add items[i] to correct bin, based on binAssignment[i]
      bins[binAssignments[i]] += items[i];


   //Bin 1 total goes above 100
   for(int i=0; i<numItems; i++)
      if (bins[i] > BINCAPACITY) {
         cout << "Bin " << i << " total goes above 100\n";
         return;
      }

   //Bin .. not used   --> its total is 0?
   //let us search for the last valid bin
   int maxBinIndex = numItems-1;
   while (bins[maxBinIndex] == 0)
      maxBinIndex--;

   //bins[0..maxBinIndex] are valid bins!
   for(int i=0; i<maxBinIndex; i++)
      if (bins[i] == 0) {
         cout << "Bin " << i << " not used\n";
         return;
      }

   cout << "Valid\n";
}

int main() {
   string line;
   int numAssignments = 0;

   //get all the items first.
   getline(cin, line);  //get one line of input
   istringstream istr(line);  //convert it to inputstringstream
   //extract the numbers from the stream into the array
   while (istr >> items[numItems]) 
      numItems++;

    //get bin assignments now.
   getline(cin, line);
   istringstream istr2(line);
   while (istr2 >> binAssignments[numAssignments])
      numAssignments++;

    if (numItems != numAssignments) {
        cout << "# of items and # of bin assignments mismatch.";
        exit(1);
    }
    validate();
}