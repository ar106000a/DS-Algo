#include<bits/stdc++.h>
using namespace std;
void rev(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int c=arr[r];
    arr[r]=arr[l];
    arr[l]=c;
    rev(arr, l+1,r-1);
}
int main(){
    int arr[8]={1,2,3,4,5,4,3,2};
    rev(arr,0,7);
    for(int num:arr){
        cout<<num<<endl;
    }
    return 0;
}