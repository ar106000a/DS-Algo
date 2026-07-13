#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//In selection sort, we start with the whole array, find the smallest number index, and swap with the first element, in next round, we loop through 1 through n-1, and find smallest again and swap with index 1, at this point, index 0,1 are sorted and we continue this till n-1, last element is auto sorted.

//Time complexity is O(n squared) in best,worst,and average case.

int main(){
    int arr[10]={5,4,2,5,8,56,43,956,43,42};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        int smallest=arr[i];
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<smallest){
                minIndex=j;
                smallest=arr[j];
            }
        }
        if(minIndex!=i){
            smallest=arr[minIndex];
            arr[minIndex]=arr[i];
            cout<< "swapping " << arr[i]<<" with "<<smallest<<endl;
            arr[i]=smallest;
        }
        
        
    }

    for(int i=0; i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}