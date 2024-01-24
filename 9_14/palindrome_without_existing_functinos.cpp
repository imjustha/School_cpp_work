#include <iostream>
//#include <fstream>

using namespace std;

//returns true or false
bool palindromeCheck(string word) {
    int n = word.length();
    int middle = n / 2; // "abccba" 6
    for(int i=0; i < middle ; i++)
        if (word[i] != word[n-1-i]) //check the character from the beginning with the equivalent at the other end
            return false;           //control comes here if it is a mismatch - so further checking needed ; return right away
    return true;
}

//returns # of mismatches
int palindromeMismatches(string word) {
    int n = word.length();
    int middle = n / 2; // "abccba" 6

    int mismatchCounter = 0;
    for(int i=0; i < middle ; i++)
        if (word[i] != word[n-1-i])
            mismatchCounter++;

    return mismatchCounter;
}

int main() {
    string input;
    cin >> input;
    string yes = input + " is a palindrome";
    string no = input + " is not a palindrome...# of mismatches : ";

    //using ternary operator
    palindromeCheck(input) ? (cout << yes) : (cout << no << palindromeMismatches(input)) ;

    //using the regular if..else
    if(palindromeCheck(ui)){
       cout << "It is a palidrome" << endl;
    }else{
        cout << "# of mismatches: " << palindromeMismatches(ui) << endl;
    }

}