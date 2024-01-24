#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string records[N];
    for (int i = 0; i < N; i++) {
        string cow1, cow2, cow3;
        cin >> cow1 >> cow2 >> cow3;
        
        if (cow1 > cow2) swap(cow1, cow2);
        if (cow1 > cow3) swap(cow1, cow3);
        if (cow2 > cow3) swap(cow2, cow3);

        records[i] = cow1 + cow2 + cow3;
    }
    
    int maxCount = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (records[i] == records[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }

    cout << setw(4) << setfill(' ') << maxCount << endl;

    return 0;
}