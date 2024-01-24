// #include <iostream>
// using namespace std;

// int main () {
//     int capacity; 
//     int item;
//     int total = 0;
    
//     cout << "Enter capatcity: ";
//     cin >> capacity;
    
//     if (capacity > 0) {
//         cout << "Input items: \n";
//         while (total < capacity){
//             cin >> item;
//             if (item + total < capacity){
//                 total += item;
//             }else{
//                 cout << "Total: " << total << endl;
//                 exit(0);
//             }

//         }
//     }
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int capacity;
//     int total = 0;
//     int ui;

//     cin >> capacity;
//     while (total < capacity){
//         cin >> ui;
//         if (ui + total < capacity){
//             total += ui;
//             cout << "Including this... current total" << total << endl;
//         }else{
//             cout << "Limited reached... Total" << total << endl;
//             exit(0);
//         }
//     }
// }
#include <iostream>
using namespace std;

int main(){
    int capacity;
    int total = 0;
    int ui;

    cin >> capacity;
    while(total < capacity){
        cin >> ui;
        total += ui;
    }
    total -= ui;
    cout << "Limit reached... Total " << total << endl;
}