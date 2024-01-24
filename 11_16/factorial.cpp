#include <iostream>
using namespace std;

int factorialRecursion(int n){
    if(n == 0 ){
        return 1;
    }else{
        int prod = n* factorialRecursion(n-1);
        cout << prod << " " ;
        return prod;
    }
}


int factorialNonRecursive(int n){
    int result = 1;
    for(int i=n; i>=1; i--){
        result *= i;
        cout << result << " ";
    }
    return result;
}

int main(){

cout << factorialNonRecursive(5) << endl;
factorialRecursion(5);

}