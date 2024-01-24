#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <sstream>

using namespace std;

// N/N/NN to NN/NN/NNNN

bool validDate(string word) {
  //CODIO SOLUTION BEGIN
   int n = word.length();

   //check total length first.
   if (n < 6 || n > 10)
      return false;

   //each char should be digit or /
   int slashes = 0;
   for(int i=0; i<n; i++)
      if (isdigit(word[i]))
         continue;
      else if (word[i] == '/')
         slashes++;
      else
         return false;

   //# of / should be 2
   if (slashes != 2)
      return false;

   //validate the actual values
   int month=0, day=0, year=0;
   static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   char temp;
   if (istringstream(word) >> month >> temp >> day >> temp >> year) {
      if (month < 1 || month > 12 || day < 1 || day > 31)
         return false;
      if (day > days[month])
         return false;
   } else
      return false;

   //month portion should be 1 or 2 chars,
   //day portion should be 1 or 2 chars too
   //year portion should be 2 or 4 chars.
   string monthStr, dayStr, yearStr;
   istringstream dateStream(word);
   getline(dateStream, monthStr, '/');
   getline(dateStream, dayStr, '/');
   getline(dateStream, yearStr, '/');
   if (monthStr.length() < 1 || monthStr.length() > 2)
      return false;
   if (dayStr.length() < 1 || dayStr.length() > 2)
      return false;
   if (yearStr.length() != 2 && yearStr.length() != 4)
      return false;
   return true;
   //CODIO SOLUTION END
}

int main() {
   string input;
   getline(cin, input);
   cout << (validDate(input) ? "valid" : "invalid" );
}