#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void moveZeroes(int arr[],int size){
        int writer=0;
        int scanner=1;
        for(int i=0;i<size;i++){
            writer=i;
            scanner=i+1;
            if(arr[writer]==0){
                for(int j=i+1;j<size;j++){
                    if(arr[scanner]!=0){
                        int temp=arr[scanner];
                        arr[scanner]=0;
                        arr[writer]=temp;
                        break;
                    }else{
                        scanner++;
                    }
                        
                    
                }
            }
        }
}
void moveZeroesOptim(int arr[],int size){
        int scanner=0;
        int writer=0;
        for(int i=0;i<size;i++){
            if(arr[scanner]!=0){
                arr[writer]=arr[scanner];
                writer++;
                scanner++;
            }
            else{
                scanner++;
            }
        }
        for(int i=writer;i<size;i++){
            arr[i]=0;
        }
}
int main(){
    int arr[8]={0,30,0,04,5,0,0,3};
    // moveZeroes(arr,8);
    moveZeroes(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<endl;
    }
}