#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int findLargest(int arr[], int size){
    int largest=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}
int main(){
    int arr[6]={32,564,68,23,98,78};
    int n=sizeof(arr)/sizeof(arr[0]);
    int largest=findLargest(arr,n);
    cout<<"Largest element is: "<<largest<<endl;
}