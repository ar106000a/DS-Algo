//Arranging the elements in ascending order
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int leftPointer=low;
    int rightPointer=high;
    while(leftPointer<rightPointer){
        while(leftPointer<high && arr[leftPointer]<=pivot ){
            leftPointer++;
        }
        while(rightPointer>low && arr[rightPointer]>pivot ){
            rightPointer--; 
        }
        if(leftPointer<rightPointer){
            int temp=arr[leftPointer];
            arr[leftPointer]=arr[rightPointer];
            arr[rightPointer]=temp;
        }
    }
    int temp=arr[rightPointer];
    arr[rightPointer]=pivot;
    arr[low]=temp;
    return rightPointer;
}
void quickSort(int arr[], int low,int high){
    if(low>=high){
        return;
    }
    int PI= partition(arr,low,high);
    quickSort(arr,low, PI-1);
    quickSort(arr,PI+1,high);
    
}
int main(){
    int arr[5]={43,32,43,21,44};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<< endl;
    }
    return 0;
}