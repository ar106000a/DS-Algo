#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
void backtrack(vector<int>& nums,vector<vector<int>>& ans, vector<int>& ds, vector<bool>& remainingOpt){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!remainingOpt[i]){
                remainingOpt[i]=true;
                ds.push_back(nums[i]);
                backtrack(nums,ans,ds,remainingOpt);
                ds.pop_back();
                remainingOpt[i]=false;
            }
        }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> ds;
    vector<bool> remainingOpt(nums.size(),false);
    backtrack(nums,result,ds, remainingOpt);
    



    return result;
}

int main(){
    vector<int> arr={1,2,3,4};
    vector<vector<int>> result= permute(arr);
    for(const auto& it:result){
        for(const auto& val:it){
            cout<<val<<", ";
        }
        cout<<endl;
    }
    return 0;
}
