#include<iostream>
#include<vector>

#include<algorithm>
#include<string>

using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    vector<int> prev=nums[0];



    for(int i=1;i<nums.size();i++){

        if(nums[i][0]<=prev[1]){
            prev[1]=max(nums[i][1],prev[1]);

        }else{
            result.push_back(prev);
            prev=nums[i];
        }
    }
    result.push_back(prev);
    return result;
}
int main(){
    vector<vector<int>> arr={{1,4},{2,3}};
    vector<vector<int>> intervals= mergeIntervals(arr);
    for(const auto& it:intervals){
        for(const auto& it2:it){
            cout<<it2<<endl;
        }
    }
}