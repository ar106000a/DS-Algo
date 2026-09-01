#include<iostream>
#include<vector>

    using namespace std;
    int reversePairsBrute(vector<int>& nums){
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j]*2){

                    cnt++;
                }
            }
        }
        return cnt;
    }

    int merge(vector<int>& nums, int left, int mid, int right){
    int low=left;
    int high=mid+1;
    vector<int> temp;
    int cnt=0;
    int cntLeft=low;
    int cntRight=high;
    while(cntLeft<=mid && cntRight<=right){
        if(nums[cntLeft]>(long long)nums[cntRight]*2){
            cnt+=(mid-cntLeft+1);
            cntRight++;
        }else{
            cntLeft++;
        }
       
    }
    
    while(low<=mid && high<=right){
        if(nums[low]<=nums[high]){
            temp.push_back(nums[low]);
            low++;
        }else{
            temp.push_back(nums[high]);
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
int reversePairs(vector<int>& nums){
    int size=nums.size()-1;
    int cnt=mergeSort(nums,0,size);
    return cnt;
}
int main(){
    vector<int> arr={40,25,19,12,9,6,2};
    int cnt= reversePairs(arr);
    cout<<cnt<<endl;
    return 0;
}