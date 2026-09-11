#include<vector>
#include<iostream>
using namespace std;
int binarySearch(vector<int>& nums,int low,int high,int target){
    int mid=(low+high)/2;
    if(target==nums[mid]){
        return mid;
    }
    if(low==high && target!=nums[mid]){
        return -1;
    }
    if(target<nums[mid]){
        if(mid==0){
            return -1;
        }
        return binarySearch(nums,low,mid-1,target);
    }else{
        return binarySearch(nums,mid+1,high,target);
    }
}
int main(){
    vector<int> arr={2,5};
    int idx= binarySearch(arr,0,(arr.size()-1),0);
    cout<<idx<<endl;
}