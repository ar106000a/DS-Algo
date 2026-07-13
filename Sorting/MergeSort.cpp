//this sort technique works on Divide and merge scenario. We divide the array into 2 hypothetical subarrays. We, then take those subarrays, sort them and merge them.

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector <int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
        
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
 
}

void mergeSort(int arr[],int low, int high){
    if(low>=high){
        return;
    }
    
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high
    );
    merge(arr,low,mid,high);
    
}

int main(){
    int arr[5]={65,345,435,5,343};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}