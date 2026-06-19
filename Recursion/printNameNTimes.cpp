#include<bits/stdc++.h>
using namespace std;
void f(int i,int n, string name){
    if(n<i){
        return;
    }
    cout<<name<<endl;
    n--;
    f(i,n,name);
}
int main(){
    int n=0;
    cin>>n;
    f(1,n,"Ali");
}