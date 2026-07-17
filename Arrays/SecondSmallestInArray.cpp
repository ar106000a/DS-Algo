#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int findSecondSmallest(int arr[],int size){
    int smallest=arr[0];
    int sSmallest=INT_MAX;
    for (int i=0;i<size;i++){
        if(arr[i]<smallest){
            sSmallest=smallest;
            smallest=arr[i];
        }else if(arr[i]<sSmallest){
            sSmallest=arr[i];
        }

    }
    return sSmallest;
}
int main(){
    int arr[6]={32,564,68,23,98,78};
    int n=sizeof(arr)/sizeof(arr[0]);
    int secondSmallest=findSecondSmallest(arr,n);
    cout<<"Second smallest element is: "<<secondSmallest<<endl;
}