#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    solution.push_back(i);
                    solution.push_back(j);
                    return solution;
                }
            }
        }
        return solution;
    }

vector<int> twoSumBest(vector<int>& nums, int target){
    vector<int> sol;
    unordered_map<int,int> temp;

    for(int i=0;i<nums.size();i++){
        int indice1=0;
        int k= target-nums[i];
        if(temp.find(k)!=temp.end()){
            indice1=temp[k];
            sol.push_back(indice1);
            sol.push_back(i);
            return sol;
        }
        temp[nums[i]]=i;


    }
    return sol;
}

int main(){
    vector<int> nums={1,2,3,4,54,3,2};
    vector<int> sol=twoSumBest(nums,58);
    for(const auto& val:sol){
        cout<<val<<endl;
    }
    return 0;
}
