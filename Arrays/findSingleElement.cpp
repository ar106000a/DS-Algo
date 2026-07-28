#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int findSingle(int arr[],int size){
    int run=0;
    for(int i=0;i<size;i++){
        run=run^arr[i];

    }
    return run;
}
int main(){
    int arr[9]={4,4,5,5,6,6,7,7,8};
    int num= findSingle(arr,9);
    cout<<num<<endl;
}