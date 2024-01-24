#include "Section.h"

#include "Section.h"

//CODIO SOLUTION BEGIN

Section::Section(int seatsInRow, int rows, int fRow) {
  seatsPerRow = seatsInRow;
  numRows = rows;
  firstRow = fRow;
  allocated = new int [numRows];
  for(int i=0; i<numRows; i++)
    allocated[i] = 0;
}
/*
const int PREMIUMROWS = 5;
const int REGULARROWS = 15;
const int SEATSPERROW = 10;
int allocatedPremium[PREMIUMROWS], allocatedRegular[REGULARROWS];
*/
//0 --> 'A', 1 --> 'B',

//For the example in slides, contents will be changing like this:
// {0, 0, 0, .... 0}
// {5, 0, 0, .... 0}
// {5, 6, 0, .... 0}
// {10, 6, 0, ... 0}

//allocate and output seat numbers
//function should work for both sections
//we need more parameters to indicate the section
//seats - number of tickets we need to allocate seats
//allocated[] - array that has # of allocted seats in each row
//numRows - number of rows for this section
//skipRows - # of rows to skip when we output row # of each seat.
bool Section::allocateTogether(int seats) {
//bool allocateTogether(int seats, int allocated[], int numRows, int skipRows)
    //check row by row for that many seats
    //if seats are available, output seat numbers "1A 1B ..."
    for(int row=0 ; row<numRows; row++)
        //same as if (SEATSPERROW >= allocated[row] + seats)
        if (seatsPerRow-allocated[row] >= seats)
        {
            while (seats--)
            {
                cout << (row+firstRow) << (char) (allocated[row]+'A') << " ";
                allocated[row]++;
            }

            cout << endl;
            return true;
        }

    return false;
}

//additional functions:

//function to find total # of available seats in the specified section
int Section::getTotalAvailableSeats() {
//int getTotalAvailableSeats(int allocated[], int numRows) {
    int totalAvailabeSeats = 0;
    for(int row=0 ; row<numRows; row++)
        totalAvailabeSeats += seatsPerRow - allocated[row];
    return totalAvailabeSeats;
}

bool Section::allocateAnyWhere(int seats) {
//bool allocateAnyWhere(int seats, int allocated[], int numRows, int skipRows)
    //compare total # of available seats vs. what we need
    if (getTotalAvailableSeats() < seats)
        return false;

    //check row by row for allocate seats
    //allocate that many seats.
    for(int row=0 ; row<numRows; row++)
        while (allocated[row] < seatsPerRow)   //is there a free seat?
        {
            cout << (row+firstRow) << (char) (allocated[row]+'A') << " ";
            allocated[row]++;
            seats--;
            if (!seats)
            {
                cout << endl;
                return true;
            }
        }
    //unreachable code! return false, just to be safe!
    return false;
}

//Character related functions:
// if (isdigit(response))
// if (isalnum(response))
// if (isspace(response))

//CODIO SOLUTION END
