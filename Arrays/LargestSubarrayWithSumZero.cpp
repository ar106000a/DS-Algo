#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int LargestSubArrayWithSumZeroBrute(vector<int>& nums){
    int sum=0;
    int length=0;
    for(int i=0;i<nums.size();i++){
        sum=0;
        for (int j=i;j<nums.size();j++){
            sum+=nums[j];

            if(sum==0){
                length=max(length, j-i+1);
            }
        }
    }
    return length;
}
int LargestSubarrayWithSumZeroOptimal(vector<int>& nums){
    int maxx=0;
    int sum=0;
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==0){
            maxx=i+1;
        }

        if(mp.find(sum)!=mp.end()){
            maxx=max(maxx,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    return maxx;
}
int main(){
    vector<int> arr={1, 2, 3, -6, 5, 4};
    int ans= LargestSubarrayWithSumZeroOptimal(arr);
    cout<<ans<<endl;
    return 0;
}