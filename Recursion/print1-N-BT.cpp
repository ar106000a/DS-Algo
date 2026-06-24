#include<bits/stdc++.h>
using namespace std;
void p(int i, int n){
    if(i<1){
        return;
    }
    
    p(i-1,n);
    cout<<i<<endl;
}
int main(){
    p(5,5);
    return 0;

}