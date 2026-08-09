#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
vector<int> findLeaders(vector<int>& nums){
    vector<int> ans;
    for(int i=0;i<nums.size()-1;i++){
        bool leader=true;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                leader=false;
                break;
            }

        }
        if(leader){
            ans.push_back(nums[i]);
        }

    }
    ans.push_back(nums.back());
    return ans;

}
vector<int> findLeadersOptimal(vector<int>& nums){
    int maximum=INT_MIN;
    vector<int> leaders;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>maximum){
            leaders.push_back(nums[i]);
            maximum=nums[i];
        }
        
    }
    return leaders;
}

int main(){
    vector<int> arr={10,22,12,3,0,6};
    vector<int> ans= findLeadersOptimal(arr);
    for(const auto& it:ans){
        cout<<it<<endl;
    }
    return 0;
}
 