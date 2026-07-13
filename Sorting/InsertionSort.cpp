//This algorithm works by taking 0-i part of array where i goes through 1-n, and places the lest element of that part of array in its correct position...
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int arr[7]={54,643,34,5,543,453,543};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        // int elem=arr[i];
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j-1];
                cout<<"Swapping "<<arr[j] <<" with "<<arr[j-1]<<endl;
                arr[j-1]=arr[j];
                arr[j]=temp;
            }else{
                break;
            }
            
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}