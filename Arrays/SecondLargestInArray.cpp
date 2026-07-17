#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int findSecondLargest(int arr[],int size){
    int largest=arr[0];
    int sLargest=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            sLargest=largest;
            largest=arr[i];
        }else if(arr[i]>sLargest){
            sLargest=arr[i];
        }


    }
    return sLargest;
}
int main(){
    int arr[6]={32,564,68,23,98,78};
    int n=sizeof(arr)/sizeof(arr[0]);

    int secondLargest=findSecondLargest(arr,n);
    cout<<"Second Largest element is: "<<secondLargest<<endl;
}