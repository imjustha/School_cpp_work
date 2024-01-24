
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    //Max of “10 5 abc 97 5” should be 97, not 10.
    string ui;
    getline(cin, ui);
    istringstream iss (ui);
    //cout << iss << endl;

    int maxNow = 0;
    int val;
    string token;

    while(iss >> token){
            //get one token from
        if( istringstream(token) >> val ){
            //if the conversion of next string into an int is possible //as val's datatype is integer
            //then check if the incoming value is lesser than what we currently have as maximum
            if(maxNow < val){
                    //if so, change our maximum value
                maxNow = val;
            }
        }
    }
    cout << maxNow << '\n';
}