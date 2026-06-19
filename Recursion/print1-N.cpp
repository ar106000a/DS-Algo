#include<bits/stdc++.h>
using namespace std;
void f(int n){
    if(n>0){
        cout<<n<<endl;

    }
    n--;
    f(n);
}
int main(){
    int n=0;
    cin>>n;
    f(n);
}