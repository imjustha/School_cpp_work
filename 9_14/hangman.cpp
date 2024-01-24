#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int playGame(string word)  //returns # of misses
{
    cout << "For testing: " << word << endl;

    //CODE HERE!
}

//we are assuming there are max 1 million words.
string words[1000000];

int main()
{
    int numWords = 0;
    ifstream finput("words.txt"); //get this file from the box folder too!
    // while (finput >> words[numWords]) -- Mac may need this one?
    while (getline(finput, words[numWords]))
        numWords++;
    finput.close();
    cout << numWords << " words read.\n";

    //select a random word
    srand(time(NULL));
    int wordNumber = rand() % numWords;

    int misses = playGame(words[wordNumber]);
    cout << "Word is " << words[wordNumber]
        << " You missed " << misses << " times." << endl;
}