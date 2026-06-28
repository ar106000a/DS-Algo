#include<bits/stdc++.h>
using namespace std;

void rev(vector<int>& arr,int n ){
    if(n<=(arr.size()/2)){
        return;
    }
    int c=arr[n-1];
    arr[n-1]=arr[arr.size()-n];
    arr[arr.size()-n]=c;
    rev(arr,n-1);
}
int main(){
    vector<int> arr={1,2,4,54,343,23,3};
    // cout<<arr.size()<<endl;
    rev(arr, arr.size());
    for(int num:arr){
        cout<<num<<endl;
    }
    return 0;
}