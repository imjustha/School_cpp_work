#include <iostream>
#include "Section.h"
using namespace std;

int main()
{
  int seatsPerRow=0, premiumRows=0, regularRows=0;
  cin >> seatsPerRow >> premiumRows >> regularRows;

  Section premium(seatsPerRow, premiumRows, 1);
  Section regular(seatsPerRow, regularRows, premiumRows+1);
    int tickets=0;
    char response;
    while (true)
    {
        cin >> response >> tickets; //in Codio, the test cases are being read from the file;
            // so this part works .... If it is run from a CodeBlocks,
            //  system will wait for another input after user enters a C
            // sorry for missing this check inside Codio.
        if (toupper(response) == 'P') {
          if (!premium.allocateTogether(tickets))
            if (!premium.allocateAnyWhere(tickets))
              cout << "Sorry, not enough seats. Please come again!\n";
        } else if (toupper(response) == 'R') {
          if (!regular.allocateTogether(tickets))
            if (!regular.allocateAnyWhere(tickets))
              cout << "Sorry, not enough seats. Please come again!\n";
        } else if (toupper(response) == 'C') {
            cout << "Good bye!\n";
            return 0;
        }
    }
}
