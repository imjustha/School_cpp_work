#include <iostream>
using namespace std;

//goal is to find the index of the minimum
//  in the portion of the array that we are asked to search for
int findMinIndex(int src[], int startIndex, int n){
    int minSoFar = src[startIndex];
    int minIndex = startIndex;
    for(int i=startIndex; i<n; i++){
        if(src[i] < minSoFar){
            //keep this in memory
            minSoFar = src[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    int arr[] = {1, 15, 7, 5, 22, 8};
    int n = sizeof(arr) / sizeof(int);

    for(int i=0; i<n; i++){
        int minIsAt = findMinIndex(arr, i, n);
        //swap first item of unsorted portion and the smallest
        int buffer = arr[minIsAt];
        arr[minIsAt] = arr[i];
        arr[i] = buffer;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " " ;
    }
}