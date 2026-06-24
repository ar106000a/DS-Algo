#include<bits/stdc++.h>
using namespace std;
void p(int i, int n){
    if(i>n){
        return;
    }
    
    p(i+1,n);
    cout<<i<<endl;
}
int main(){
    p(1,4);
    return 0;
}