#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<int> UnionSortedArr(vector<int> &arr1,vector<int> &arr2){
    int a=0;
    int b=0;
    vector<int> newArr;
    while(a<arr1.size() && b<arr2.size()){
        if(arr1[a]<arr2[b]){
            if(newArr.empty() || newArr.back()!=arr1[a]){
                newArr.push_back(arr1[a]);
            }
            a++;
        }else if( arr1[a]>arr2[b]){
            if(newArr.empty() || newArr.back()!=arr2[b]){
                newArr.push_back(arr2[b]);
            }
            b++;
        }else{
            if(newArr.empty() || newArr.back()!=arr1[a]){
                newArr.push_back(arr2[b]);
            }
            a++;
            b++;
        }
    }
    while(a<arr1.size()){
        if(newArr.empty() || newArr.back()!= arr1[a]){
            newArr.push_back(arr1[a]);
        }
        a++;
    }
    while(b<arr2.size()){
        if(newArr.empty() || newArr.back()!= arr2[b]){
            newArr.push_back(arr2[b]);
        }
        b++;
    }
    return newArr;
}
int main(){
    vector<int> arr1={33,44,55,66,77};
    vector<int> arr2={11,22,33,44,55};
    vector<int> unionArr = UnionSortedArr(arr1,arr2);
    for(int i:unionArr){
        cout<< i<<endl;
    }
    return 0;
}
