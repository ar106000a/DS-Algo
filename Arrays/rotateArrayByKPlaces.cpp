#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void kLeftRotate(int arr[],int size,int k){
        vector<int> temp;
        for(int i=0;i<k;i++){
            temp.push_back(arr[i]);
        }
        for(int i=k; i<size;i++){
            arr[i-k]=arr[i];

        }
        for(int i=size-k;i<size;i++){
            arr[i]=temp[i-k];
        }
     
}
// void kLeftRotate(int arr[],int size,int k){
//     int revK=size-k;
//     int temp=arr[0];
//     int secTemp;
//     int index=0;
//     for(int i=0;i<size;i++){
//         secTemp=arr[(index+revK)%size];
//         arr[(index+revK)%size]=temp;
//         temp=secTemp;
//         index=index+revK;
//     }
// }
void kRightRotate(int nums[],int size,int k){
        int revK=size-k;
        vector<int> temp;
        for(int i=0;i<revK;i++){
            temp.push_back(nums[i]);
        }
        for(int i=revK; i<size;i++){
            nums[i-revK]=nums[i];

        }
        for(int i=size-revK;i<size;i++){
            nums[i]=temp[i-k];
        }
     
}
// void kRightRotate(int arr[],int size,int k){
//     int temp=arr[0];
//     int secTemp;
//     int index=0;
//     for(int i=0;i<size;i++){
//         secTemp=arr[(index+k)%size];
//         arr[(index+k)%size]=temp;
//         temp=secTemp;
//         index=index+k;
//     }
// }

void kOptRightRotate(int arr[],int size, int k){
    k=abs(k%size);
    k=size-k;
    for(int i=0;i<(k/2);i++){
            int temp=arr[i];
            arr[i]=arr[k-i-1];
            arr[k-i-1]=temp;
        }
        for(int i=k;i<(k+(size-k)/2);i++){
            int temp=arr[i];
            arr[i]=arr[size+k-i-1];
            arr[size+k-i-1]=temp;
        }
        for(int i=0;i<(size/2);i++){
            int temp=arr[i];
            arr[i]=arr[size-i-1];
            arr[size-i-1]=temp;
        }
}
int main(){
    // int arr[5]={3,4,5,6,7};
    int arr[4]={-1,-100,3,99};
    // rotate(arr,5);
    // kLeftRotate(arr,5,2);
    // kRightRotate(arr,4,2);
    kOptRightRotate(arr,4,2);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
