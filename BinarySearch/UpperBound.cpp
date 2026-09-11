#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int>& nums,int left,int right,int target,int ans){
        int mid=(left+right)/2;
        if(left>right){
            return ans;
        }
        if(left==right && nums[mid]<=target){
            return ans;
        }
        if(left==right && nums[mid]>target){
            ans=mid;
            return ans;
        }
        if(nums[mid]>target){
            ans= mid;
            ans= bs(nums,left,mid-1,target,ans);
        }else{
            ans= bs(nums,mid+1,right,target,ans);
        }
        
        return ans;
        
    }
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int ans=arr.size();
        ans= bs(arr,0,arr.size()-1,target,ans);
        return ans;
    }
    int main(){
        vector<int> arr={2,3,7,10,11,11,25};
        int ans= lowerBound(arr,9);
        cout<<ans<<endl;
    }