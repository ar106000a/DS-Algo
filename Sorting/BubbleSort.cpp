// It works by swapping the largest to the right by adjacent swapping.

//time complexity: O(n squared) for worst case-avg case complexity..., for best case we can add a new isSwapped variable; Now the complexity is O(n) because the outer loop runs for once and the inner loop runs for n times, so bigO(n)
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int arr[5]={32,43,234,534,543};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){
        bool isSwapped=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                cout<<"swapping "<<arr[j]<<" with "<<arr[j+1]<<endl;
                arr[j+1]=arr[j];
                arr[j]=temp;
                isSwapped=true;
            }
        }
        cout<<"runs"<<endl;
        if(isSwapped==false){
            break;
        }

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}