#include<vector>
#include<iostream>

using namespace std;
int floor(vector<int>& nums,int target, int left, int right,int ans){
    if(left>right){
        return ans;
    }
    int mid=(left+right)/2;
    if(nums[mid]==target){
        ans=nums[mid];
        return ans;
    }
    if(left==right && nums[mid]<target){
        if(ans<nums[mid]){
            return nums[mid];
        }else{
            return ans;
        }
    }
    if(left==right && nums[mid]>target){
        return ans;
    } 
    if(nums[mid]<target){
        ans= nums[mid];
        ans=floor(nums,target,mid+1,right,ans);
    }else{
        ans= floor(nums,target,left,mid-1,ans);
    }
    return ans;
}
int ceil(vector<int>& nums,int target, int left, int right,int ans){
    if(left>right){
        return ans;
    }
    int mid=(left+right)/2;
    if(nums[mid]==target){
        ans=nums[mid];
        return ans;
    }
    if(left==right && nums[mid]>target){
        if(ans>nums[mid]){
            return nums[mid];
        }else{
            return ans;
        }
    }
    if(left==right && nums[mid]<target){
        return ans;
    } 
    if(nums[mid]<target){
        ans=ceil(nums,target,mid+1,right,ans);
    }else{
        ans=nums[mid];
        ans= ceil(nums,target,left,mid-1,ans);
    }
    return ans;
}
vector<int> floorNceil(vector<int>& nums, int target){
    int floorInt= floor(nums,target,0,nums.size()-1,INT_MAX);
    int ceilInt= ceil(nums,target,0,nums.size()-1,INT_MIN);
    return {floorInt,ceilInt};
}
int main(){
    vector<int> arr={-10, -5, -3, -1, 0, 4, 7};
    vector<int> ans= floorNceil(arr,-4);
    cout<< ans[0] << "  "<<ans[1]<<endl;
}
