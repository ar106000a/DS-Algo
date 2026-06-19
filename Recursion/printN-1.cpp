#include<bits/stdc++.h>
using namespace std;
void f(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    i++;
    f(i,n);
}
int main(){
    int n=0;
    cin>>n;
    f(1,n);
}