#include<iostream>
#include<vector>
using namespace std;
int fo(vector<int>& nums, int left, int right, int target,int ans){
    if(left>right){
        return ans;
    }
    int mid=(left+right)/2;
    if(nums[mid]==target){
        ans=mid;
        return fo(nums,left,mid-1,target,ans);
    }
    if(left==right){
        if(nums[mid]==target){
            return mid;
        }else{
            return ans;
        }
    }
    if(nums[mid]>target){
        return fo(nums,left,mid-1,target,ans);
    }else{
        return fo(nums,mid+1,right,target,ans);
    }
    
}
int lo(vector<int>& nums, int left, int right, int target,int ans){
    if(left>right){
        return ans;
    }
    int mid=(left+right)/2;
    if(nums[mid]==target){
        ans=mid;
        return lo(nums,mid+1,right,target,ans);
    }
    if(left==right){
        if(nums[mid]==target){
            return mid;
        }else{
            return ans;
        }
    }
    if(nums[mid]>target){
        return lo(nums,left,mid-1,target,ans);
    }else{
        return lo(nums,mid+1,right,target,ans);
    }
    
}
vector<int> falo(vector<int>& nums, int target){
    int firstOccurance= fo(nums,0,nums.size()-1,target,-1);
    int lastOccurance= lo(nums,0,nums.size()-1,target,-1);
    return {firstOccurance,lastOccurance};
}
int main(){
    vector<int> arr={5,7,7,8,8,10};
    vector<int> ans= falo(arr,9);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}