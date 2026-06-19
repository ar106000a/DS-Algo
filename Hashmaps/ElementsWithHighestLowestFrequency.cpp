#include<bits/stdc++.h>
using namespace std;

void highLowFreq(int arr[],int n){
    unordered_map<int,int> map;

    for (int i=0;i<n;i++){
        map[arr[i]]+=1;
    }

    int maxFreq=0;
    int maxElem=0;
    int minFreq=n;
    int minElem=0;
    for(auto it:map){
        int elem=it.first;
        int freq=it.second;
        if(freq>maxFreq){
            maxFreq=freq;
            maxElem=elem;
        }
        
        if(freq<minFreq){
            minFreq=freq;
            minElem=elem;
        }
    }
    cout<<"Highest Frequency is of element: "<< maxElem<<" and is: "<<maxFreq<<endl;
    cout<<"Lowest Frequency is of element: "<< minElem<<" and is: "<<minFreq<<endl;
}

int main(){

    int arr[]={1,22,3,3,4,5,4,5,3,4,32};
    int n= sizeof(arr)/sizeof(arr[0]);
    highLowFreq(arr,n);
}