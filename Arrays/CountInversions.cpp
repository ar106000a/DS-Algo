#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int countInversionsBrute(vector<int>& nums){
    int count=0;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<nums[i]){
                count++;
            }
        }
    }
    return count;
}

int merge(vector<int>& nums, int left, int mid, int right){
    int low=left;
    int high=mid+1;
    vector<int> temp;
int cnt=0;

    while(low<=mid && high<=right){
        if(nums[low]<=nums[high]){
            temp.push_back(nums[low]);
            low++;
        }else{
            temp.push_back(nums[high]);
            cnt+=(mid-low+1);
            high++;
        }
    }
    while(low<=mid){
        temp.push_back(nums[low]);
        low++;
    }
    while(high<=right){
        temp.push_back(nums[high]);
        high++;
    }
    for(int i=0;i<temp.size();i++){
        nums[i+left]=temp[i];
    }
    return cnt;

}
int mergeSort(vector<int>& nums, int left, int right){
    int cnt=0;
    if(left>=right){
        return cnt;
    }
    int mid= (left+right)/2;
    cnt+=mergeSort(nums,left,mid);
    cnt+=mergeSort(nums,mid+1,right);
    cnt+=merge(nums, left, mid,right);
    return cnt;
}
int countInversions(vector<int>& nums){
    int size=nums.size()-1;
    int cnt=mergeSort(nums,0,size);
    return cnt;
}
int main(){
    vector<int> arr={4,5,6,9,8};
    int count= countInversions(arr);
    cout<<count<<endl;
    return 0;
}