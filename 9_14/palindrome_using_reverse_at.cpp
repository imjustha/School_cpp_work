#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//returns true or false
bool palindromeCheck(string word) {
    string reversed = word; //copy the word
    reverse(reversed.begin(), reversed.end()); //use existing function to reverse the copied word

    for(int i=0; i<word.length()/2; i++){   //check from the beginning until the middle
        if(word.at(i) != reversed.at(i)){   //if a mismatch is found, there is no point in checking further
            return false;
        }
    }
    //if control is still inside the function,
    //  it must be because, it went through the for loop
    //  meaning that word and its reverse matched - so return true
    return true;
}

//returns # of mismatches
int palindromeMismatches(string word) {
    int mismatchCount = 0;      //initialize the accumulator to 0
    string reversed = word;     //use existing function to reverse the copied word
    reverse(reversed.begin(), reversed.end());  //use existing function to reverse the copied word

    for(int i=0; i<word.length()/2; i++){       //check from the beginning until the middle
        if(word.at(i) != reversed.at(i)){       //if a mismatch is found,
            mismatchCount++;                    //increase the accumulator by 1
        }
    }
    return mismatchCount;
}

int main(){

    string ui;
    cout << "Enter a word : ";
    cin >> ui;

    if(palindromeCheck(ui)){
       cout << ui << " is a palindrome" << endl;
    }else{
        cout << ui <<  " is not a palindrome...# of mismatches: " << palindromeMismatches(ui) << endl;
    }

}