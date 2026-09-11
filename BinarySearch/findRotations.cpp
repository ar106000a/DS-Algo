#include<iostream>
#include<vector>
using namespace std;

int findMinimum(vector<int>& nums,int left,int right,int minimum){
    if(left>right){
        return minimum;
    }
    int mid=(left+right)/2;
    if(nums[mid]<=nums[right] && nums[left]<=nums[mid]){
       if(nums[left]<nums[minimum]){
            return left;
       }else{
        return minimum;
       }
    }else if(nums[mid]>= nums[left] && nums[right]<nums[mid]){
        if(nums[right]<nums[minimum]){
            minimum=right;
       }
        return findMinimum(nums,mid+1,right,minimum);
    }else if(nums[mid]<=nums[right] && nums[left]>nums[mid]){
       if(nums[mid]<nums[minimum]){
            minimum=mid;
       }
        return findMinimum(nums,left,mid-1,minimum);
    }else{
        cout<<"Edge case not handled!"<<endl;
        return minimum;
    }
    return minimum;
}

int main(){
    vector<int> arr={2, 2,2,2, 2};
    int ans= findMinimum(arr,0,arr.size()-1,0);
    cout<<ans<<endl;
    cout<<(arr.size()-ans)%arr.size()<<endl;
    return 0;
}