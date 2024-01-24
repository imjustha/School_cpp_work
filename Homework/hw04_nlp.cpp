#include <iostream>
#include <string>
#include <sstream>
#include <limits>
/*
add up numbers 10 56 12 also 89 and output the total
give me the average of 80 and all these 85 90 92 56
what is the max of 56 12 98 56 23 12 98
find the min among 34 98 24 76 100
11.1 22.2 33.3 44.4 total these numbers
tell me the purpose of life
ok that is enough bye
*/

using namespace std;

int main(){
    //read a line
    string line;
    while (getline(cin, line)) {
        //line will be : add up numbers 10 56 12 also 89 and output the total
        istringstream lineInput(line);
        string word;
        double total = 0, counter = 0, avg = 0, maxSoFar = 0, minSoFar = 100000;

        //get one word at a time!
        //lineInput will be all words in line separated by space
        while (lineInput >> word) {
            double value;
            //is the word number or string?
            //if number, make it count or use it up
            if (istringstream(word) >> value){
                //number
                cout << value << " ";
                total += value;
                counter++;
                if(value > maxSoFar ){
                    //going forward, we need to remember the current value as max
                    maxSoFar = value;
                }
                if(value < minSoFar){
                    minSoFar = value;
                }
            }
        }
        //now that we have processed the numbers, identify what the user wants to do with the numbers
        //as the lineInput would have reached the end of the line after reading all the numbers,
        //  make it point to the first word in that line again
        lineInput = istringstream(line);
        bool validCommand = false;
        while (lineInput >> word) {
                //string!
                if(word == "total"){
                    cout << "total " << total << endl;
                    validCommand = true;
                }else if(word == "average"){
                    cout << "average " << total/(counter*1.0) << endl;
                    validCommand = true;
                }else if(word == "min"){
                    cout << "min " << minSoFar << endl;
                    validCommand = true;
                }else if(word == "max"){
                    cout << "max " << maxSoFar << endl;
                    validCommand = true;
                }else if(word == "bye"){
                    cout << "OK " << "bye!" << endl;
                    validCommand = true;
                }
        }
        if(validCommand){
            continue;
        }else{
            cout << line << " - I am not yet that smart to answer this one!" << endl;
        }
    }
}