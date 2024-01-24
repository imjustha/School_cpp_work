//FREEZE CODE BEGIN
#include "TestAttempt.h"

using namespace std;

int main()
{
    int numQuestions;
    string correct;
    cout << "Enter # of questions in the test: ";
    cin >> numQuestions;
    cout << "Enter the question #s you got right: ";
    getline(cin, correct); //go past end of line
    getline(cin, correct);
    TestAttempt attempt1(numQuestions, correct);

    cout << "Enter the question #s your friend got right: ";
    getline(cin, correct);
    TestAttempt attempt2(numQuestions, correct);
    cout << endl;
    //now, you can work with both objects!
    cout << "A+B: " << attempt1 + attempt2 << endl;
    cout << "A^B: " << (attempt1 ^ attempt2) << endl;
    cout << "A%B: " << attempt1 % attempt2 << endl;
    cout << "A-B: " << attempt1 - attempt2 << endl;
    cout << "B-A: " << attempt2 - attempt1 << endl;
}
//FREEZE CODE END

/*
input:
25
1 2 3 4 5 7 9 10 18 19 20 21 22 23 12 13 14 15 16 8
2 5 6 7 8 15 16 17 18 19 20 21 22 23 24 25

output:
A+B: 1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20 21 22 23 24 25  (union of 2 sets)
A^B: 2 5 7 8 15 16 18 19 20 21 22 23 (intersection of 2 sets)
A%B: 11 (both of you got these wrong)
A-B: 1 3 4 9 10 12 13 14  (you got these right, your friend missed)
B-A: 6 17 24 25 (your friend got these right, you missed)

*/
