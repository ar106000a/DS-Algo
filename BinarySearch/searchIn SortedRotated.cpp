#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums,int left,int right, int target){
    if(left>right){
        cout<<left<<"and"<<right<<endl;
        return -1;
    }
    int mid=(left+right)/2;
    if(target==nums[mid]){
        return mid;
    }
    if(nums[mid]<=nums[right] && nums[mid]>=nums[left]){
        if(target>nums[mid]){
            return search(nums,mid+1,right,target);
        }else{
            return search(nums,left,mid-1,target);
        }
    }
    else if(nums[mid]>=nums[left]){
        if(target<nums[mid] && target>= nums[left]){
            return search(nums,left,mid-1,target);
        }else if(target<nums[mid] && target<nums[left]){
            return search(nums,mid+1,right,target);
        }else{
            return search(nums,mid+1,right,target);
        }
    }else{
        if(target>nums[mid] && target>nums[right]){
            return search(nums,left,mid-1,target);
        }else if(target>nums[mid] && target<=nums[right]){
            return search(nums,mid+1,right,target);
        }else{
            return search(nums,left,mid-1,target);
        }
    }
}
int main(){
    vector<int> arr={3,1};
    int size=arr.size();
    int ans = search(arr,0,size-1,1);
    cout<<ans<<endl;
    return 0;
}

//Alright this was a brainfuck
