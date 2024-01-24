#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAXFILES = 10;
const int MAXROWS = 1000;

//There are 2 distinct approaches for this problem:
//1. Sequential processing - one file at a time. You need total[MAXROWS] array 
//2. Row-wise processing - open all input files. Read one value from each, total them and output.
//                         need an array of ifstream objects open for reading files in parallel.
//If you are excited, you can implement both!

//CODIO SOLUTION BEGIN
/*
int total[MAXROWS];

int main() {
   string line, filename;
   getline(cin, line);

   istringstream lineInput(line);

   //process one file at a time - sequential processing
   //so we need total[] array for keeping track of row-wise totals so far.
   
   int numRows = 0;
   while (lineInput >> filename) {
      ifstream finput(filename);
      int row = 0, value = 0;
      while (finput >> value)
         total[row++] += value;
      numRows = row;
      finput.close();
   }

   //all files have been processed - output the final totals.
   ofstream foutput("output.txt");
   for(int i=0; i<numRows; i++)
      foutput << total[i] << endl;
   foutput.close();

   return 0;
}
*/
int main() {
   string line, filename;
   ifstream finputs[MAXFILES];

   getline(cin, line);
   istringstream lineInput(line);

   //read the filenames and open them for reading!
   int numFiles=0;
   while (lineInput >> filename)
      finputs[numFiles++].open(filename);

   ofstream foutput("output.txt");

   //read all the data files in parallel, i.e. one row at a time
   while (true) {
      int total=0, value=0;
      for(int i=0; i<numFiles; i++)
        if (finputs[i] >> value)
            total += value;
        else {
            foutput.close();
            exit(0);
        }
      foutput << total << endl;
   }
}

//CODIO SOLUTION END