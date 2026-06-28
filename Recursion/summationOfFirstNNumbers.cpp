#include<bits/stdc++.h>
using namespace std;
void p(int n, int sum){
    if(n<0){
        cout<<sum<<endl;
        return;

    }
    p(n-1,sum+n);
    
}
int functional(int n){
    if (n==0){
        return 0;
    }
    return n + functional(n-1); 
}
int main(){    
    // parameterized way
    p(4,0);
    // functional way
    cout<< functional(4)<< endl;
    return 0;
}