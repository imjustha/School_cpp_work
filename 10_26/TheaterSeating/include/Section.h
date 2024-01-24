#ifndef SECTION_H
#define SECTION_H


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Section {
  public:
    Section(int seatsInRow, int rows, int fRow);
    //allocates seats together if possible
    bool allocateTogether(int seats);
    //allocates seats anywhere...
    bool allocateAnyWhere(int seats);
    //finds total # of free seats
    int getTotalAvailableSeats();

  private:
    int seatsPerRow, numRows, firstRow;
    int *allocated; //keeps track of how many seats are allocated in each row!
};

#endif // SECTION_H
