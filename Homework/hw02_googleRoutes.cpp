#include <iostream>
#include <string>

using namespace std;

int main() {
  //CODIO SOLUTION BEGIN
    int numRoutes = 0, bestRoute = 0;
    double valueMinute  = 0, minutes = 0, toll = 0;
    double bestCostSoFar = 10000000000;

    cout << "Enter # of routes: ";
    cin >> numRoutes;
    cout << "Enter value of one minute of your time: ";
    cin >> valueMinute;

    for(int route=1 ; route<=numRoutes; route++) {
        cout << "Enter travel time for route #" << route << ": ";
        cin >> minutes;
        cout << "Enter toll for route #" << route << ": ";
        cin >> toll;
        double cost = minutes * valueMinute + toll;
        if (cost < bestCostSoFar) {
            bestCostSoFar = cost;
            bestRoute = route;
        }
    }
    cout << "Best route is #" << bestRoute << endl;
    //CODIO SOLUTION END
}