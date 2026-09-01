#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>

using namespace std;
int firstMissingPositiveBrute(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
            int temp=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];
            nums[i]=temp;
        }
    }

    for(int i=0;i<n;i++){
        if(nums[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}
int main(){
    vector<int> arr={3,4,-1,1};
    int ans= firstMissingPositiveBrute(arr);
    cout<<ans<<endl;
    return 0;
}