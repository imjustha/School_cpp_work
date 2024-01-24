#include <iostream>
using namespace std;

int main()
{ 
//CODIO SOLUTION BEGIN
// declare variables and getting user input
   int numBowls;
   cin >> numBowls;

   int numDays;
   cin >> numDays;
 
   int numInterested; 
   cin >> numInterested;

   int count = 0;
   int cereal[numDays];

// getting user input of amount of bowls in loop
   for(int x = 0; x < numDays; x++)
   {
      cin >> cereal[x];
   }
// calculating and output final count
   for(int z = 0; z < numDays; z++)
   {
      if(cereal[z] >= numInterested)
      {
         count++;
      }

   }
   cout << count;

   return 0;
//CODIO SOLUTION END
}