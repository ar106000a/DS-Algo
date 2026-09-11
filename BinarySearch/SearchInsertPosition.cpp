#include<iostream>
#include<vector>
using namespace std;

int findPos(vector<int>& nums, int left,int right,int target){
    if(left>right){
        return left;
    }
    int mid=(left+right)/2;

    if(nums[mid]==target){
        return mid;
    }
    if(left==right && nums[mid]!=target){
        if(nums[mid]>target){
            return mid;
        }else{
            return mid+1;
        }
    }
    if(nums[mid]<target){
        return findPos(nums,mid+1,right,target);
    }else{
        if(mid==0){
            if(nums[mid]<target){
                return mid+1;
            }else{
                return mid;
            }
        }
        return findPos(nums,left,mid-1,target);
    }

}
int main(){
    vector<int> arr={3,5,7,9,10};
    cout<< findPos(arr,0,arr.size()-1,8)<<endl;
}