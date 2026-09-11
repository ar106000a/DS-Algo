#include<iostream>
#include<vector>
using namespace std;

int findMinimum(vector<int>& nums,int left,int right,int minimum){
    if(left>right){
        return minimum;
    }
    int mid=(left+right)/2;
    if(nums[mid]<=nums[right] && nums[left]<=nums[mid]){
        
        return min(minimum,nums[left]);
    }else if(nums[mid]>= nums[left] && nums[right]<nums[mid]){
        minimum=min(minimum,nums[right]);
        return findMinimum(nums,mid+1,right,nums[right]);
    }else if(nums[mid]<=nums[right] && nums[left]>nums[mid]){
        minimum= min(minimum,nums[mid]);
        return findMinimum(nums,left,mid-1,minimum);
    }else{
        cout<<"Edge case not handled!"<<endl;
        return minimum;
    }
    return minimum;
}

int main(){
    vector<int> arr={4,5,1,2,3};
    int ans= findMinimum(arr,0,arr.size()-1,INT_MAX);
    cout<<ans<<endl;
    return 0;
}