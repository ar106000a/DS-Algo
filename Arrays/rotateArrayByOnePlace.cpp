#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(int arr[],int size){
    int temp=arr[0];
    int secTemp;
    for(int i=0;i<size;i++){
        secTemp=arr[(i+1)%size];
        arr[(i+1)%size]=temp;
        temp=secTemp;
    }
}
void leftRotate(int arr[],int size){
    int temp=arr[0];
    for(int i=1;i<size;i++){
        arr[i-1]=arr[i];
    }
    arr[size-1]=temp;

}
int main(){
    int arr[5]={3,4,5,6,7};
    // rotate(arr,5);
    leftRotate(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
