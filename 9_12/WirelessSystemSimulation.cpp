#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int capacity=0;
    cin >> capacity;

    string line, event;
    getline(cin, line); //to get rid of current end of line
    getline(cin, line);

    //need variables to keep track of current usage & also for output summary
    int regular=0, emergency=0, regularAccepted=0, emergencyAccepted=0;
    int regularDenied=0, emergencyDenied=0, regularForcedOut=0;

    //CODIO SOLUTION BEGIN

    istringstream lineInput(line);
    while (lineInput >> event)
    {
        if (event == "N")
        {
            if (regular+emergency < capacity)
            {
                regular++;
                regularAccepted++;
            }
            else
                regularDenied++;
        }
        else if (event == "E")
        {
            if (regular > 0)
                regular--;
        }
        else if (event == "NE")
        {
            if (regular+emergency < capacity)
            {
                emergency++;
                emergencyAccepted++;
            }
            else if (regular > 0)
            {
                regular--;
                emergency++;
                emergencyAccepted++;
                regularForcedOut++;
            }
            else
                emergencyDenied++;
        }
        else if (event == "EE")
            if (emergency > 0)
                emergency--;
    }
    //CODIO SOLUTION END

    cout << regularAccepted << " " << regularDenied << " "
         << emergencyAccepted << " " << emergencyDenied << " " << regularForcedOut << endl;
}