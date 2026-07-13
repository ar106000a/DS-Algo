//In this module, we ll be writing fibbonacci sequence and the calculation of Nth fibonacci number using multipe recursion calls(2 in this case)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin >> n;
    cout<<fib(n)<<endl;
    return 0;
}