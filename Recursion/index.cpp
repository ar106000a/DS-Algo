#include <bits/stdc++.h>
using namespace std;
int count=0;
void print(){
    cout<< ::count <<endl;
    ::count++;
    if(::count<10){
    print();
    }
}
int main(){
    print();
}