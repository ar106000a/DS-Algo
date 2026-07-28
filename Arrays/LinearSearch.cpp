#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int LinearSearch(int arr[],int size,int target){
    
    int idx=-1;
    for(int i=0;i<size;i++){
        if (arr[i]==target){
            idx=i;
            break;
        }

    }
    return idx;
}

int main(){
    int arr[5]={1,2,3,4,5};
    int idx= LinearSearch(arr, 5,5);
    cout<<"Target "<<5<<" is at index "<<idx<<endl;
}