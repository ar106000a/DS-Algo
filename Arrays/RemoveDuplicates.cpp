#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int removeDuplicates(int arr[],int size){
    bool breakOuter=false;
    int count=1;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]<arr[j]){
                arr[i+1]=arr[j];
                count++;
                break;
            }else{
                if(j==size-1){
                    breakOuter=true;
                }
            }
        }
        if(breakOuter){
            break;
        }

    }
    return count;
}
int twoPRemoveDuplicates(int arr[],int size){
    int writer=0;
    int scanner=1;
    int count=1;
    for(int i=0;i<size-1;i++){
        if(arr[scanner]!=arr[writer]){
            writer++;
            arr[writer]=arr[scanner];
            count++;
        }
        scanner++;
    }
    return count;
}
int main(){
    int arr[16]={1,1,2,3,4,4,4,5,6,6,6,7,7,7,43,43};
    int size=16;
    // int nSize=removeDuplicates(arr,size);
    //in worst case, this ll go for n*n complexity which we definitely do not want, so we ll enhance it with 2 pointers
    int nSize=twoPRemoveDuplicates(arr,size);
    for(int i=0;i<nSize;i++){
        cout<<arr[i]<<endl;
    }
}