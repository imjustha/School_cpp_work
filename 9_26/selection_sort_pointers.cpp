#include <iostream>
using namespace std;

//find the smallest item from n items starting from current position
int * smallest (int *currentp, int n){
    int * smallestSoFar = currentp; //assume first item is the smallest
    int * endp = currentp + n; //know our boundary on the other side

    while(++currentp < endp){
        if(*currentp < *smallestSoFar){
            //going forward, we need to remember correctly
            smallestSoFar = currentp;
        }
    }
    return smallestSoFar;
}

void selectionSort(int *items, int n){
    for(int i=0; i<n-1; i++){
        int *smallp = smallest(&items[i], n-i);
        //find the smallest item's address from the unsorted portion
        //swap smallest item with the first item of the unsorted portion
        int temp = *smallp;
        *smallp = items[i];
        items[i] = temp;
    }
}

int main(){
    int arr[] = {1, 15, 7, 5, 22, 8};
    int n = sizeof(arr) / sizeof(int);

    selectionSort(arr, n);
     for(int i=0; i<n; i++){
        cout << arr[i] << " " ;
    }
}