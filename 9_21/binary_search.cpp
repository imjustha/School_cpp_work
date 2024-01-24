#include <iostream>
using namespace std;

int main(){

    //start with sorted array
    int arr[] = {1, 5, 15, 9, 13, 17, 23, 33, 67, 71};
    int n = sizeof(arr) / sizeof(int);

    int low = 0;
    int high = n - 1; //as indices run from 0..(n-1)
    int middle;

    int srchFor;
    cin >> srchFor;

    while(low <= high){
        middle = (low + high) / 2;
        cout << "Comparing " << srchFor << " & " << arr[middle] << endl;
        if(srchFor < arr[middle]){
            //focus on the left of middle
            //range starts from low until jsut before middle
            //high should be reset to 1 element before middle
            high = middle - 1;
        }else if(srchFor > arr[middle]){
            //focus on the right of middle
            //  range starts from just above middle to high
            //  so, low needs to reset tp 1 element after middle
            low = middle + 1;
        }else{
            //control comes here if the searching item is same as middle
            cout << "Found " << endl;
            exit(0);
        }
    }//end of while
    //control comes here whenever the search range crosses over
    //either high was reset to less than low
    //or low was reset to higher than high
    //which means - item was not found
    cout << "Not found"  << endl;
}
