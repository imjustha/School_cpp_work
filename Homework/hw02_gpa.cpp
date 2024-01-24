#include <iostream>
#include <iomanip>

using namespace std;

// A -> 4, B -> 3, C -> 2, D -> 1, otherwise return 0
int letterToPoints(char grade) {
  //CODIO SOLUTION BEGIN
   if (grade == 'A')
      return 4;
   if (grade == 'B')
      return 3;
   if (grade == 'C')
      return 2;
   if (grade == 'D')
      return 1;
      
   return 0;
   //CODIO SOLUTION END
}

int main() {
  //CODIO SOLUTION BEGIN
   int gradePoints = 0, creditHours = 0, hours = 0, numCourses = 0;
   char letter = ' ';
   
   cin >> numCourses;
   for(int i=0; i<numCourses; i++) {
      cin >> hours >> letter;
      gradePoints += hours * letterToPoints(letter);
      creditHours += hours;
      cout << "GPA so far: " << fixed << setprecision(2) << (gradePoints * 1.0) / creditHours << endl;
   }
   cout << "Final GPA: " << fixed << setprecision(2) << (gradePoints * 1.0) / creditHours << endl;
  //CODIO SOLUTION END
}