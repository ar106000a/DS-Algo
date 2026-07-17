#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
bool checkSortedAndRotated(int arr[],int size){
    bool flag=true;
    for(int i=0;i<size;i++){
       flag=true;
       for(int j=i;j<size+i-1;j++){
        if(arr[(j%size)+1]<arr[j%size]){
            flag=false;
            cout<<arr[(j%size)+1]<<" is not less than "<<arr[j%size]<< endl;
        }
        
       }
       if(flag==true){
        return true;
       }
    }
    return flag;
}
bool checkOptSortedAndRotated(int arr[],int size){
    int drop=0;
    int flag=true;
    for(int i=0;i<size;i++){
        if(arr[i]>arr[(i+1)%size]){
            drop++;
        }
    }
    if(drop>1){
        return false;
    }else{return true;}
}
int main(){
    int arr[6]={9,10,1,3,4,6};
    int size=6;
    // bool check=checkSortedAndRotated(arr,size);
    //the above method used n*n time complexity and is not optimal, but we can definitely optimize it till O(n), by considering that in a sorted and rotated array, there ll be at most one drop and then the element ll rise again, lets write another method for it:
    bool OptCheck=checkOptSortedAndRotated(arr,size); 
    cout<<"Sorted and rotated check is: "<<OptCheck<<endl;
}