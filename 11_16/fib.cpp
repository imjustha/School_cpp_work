#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int fibNonRecursive(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    //need to remember past 2 values
    int previous = 0;
    int current = 1;
    for(int i=2; i<=n; i++){
        int  total = current + previous;
        previous = current;
        current  = total;
        //cout << total << " " ;
    }
    return current;
}
int main(){
    //cout << fib(50);
    cout << fibNonRecursive(30);
}