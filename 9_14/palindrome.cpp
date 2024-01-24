#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool palindromeCheck(string word) {
    string reversed = word;
    std::reverse(reversed.begin(), reversed.end());

    for(int i=0; i<word.length()/2; i++){
        if(word.at(i) != reversed.at(i)){
            return false;
        }
    }
}

int palindromeMismatches(string word) {
    int mismatchCount = 0;
    string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    for(int i=0; i<word.length()/2; i++){
        if(word.at(i) != reversed.at(i)){
            mismatchCount++;
        }
    }
    return mismatchCount;
}

int main(){

    string ui;
    cout << "Enter a word : ";
    cin >> ui;

    if(palindromeCheck(ui)){
       cout << "It is a palidrome" << endl;
    }else{
        cout << "# of mismatches: " << palindromeMismatches(ui) << endl;
    }

}