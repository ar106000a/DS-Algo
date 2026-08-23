#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
vector<vector<int>> ThreeSumBruteForce(vector<int>& nums){
    set<vector<int>> result;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    result.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> final(result.begin(),result.end());
    return final;
}
vector<vector<int>> ThreeSumBetter(vector<int>& nums){
    //TIme complexity: n*n*log(m)
    //Space complexity: n + 2(no of unique triplets)
    set<int> store;
    set<vector<int>> hashStore;
    for(int i=0;i<nums.size();i++){
        store.clear();
        for(int j=i+1;j<nums.size();j++){
            int target= -(nums[i]+nums[j]);
            if(store.find(target)!=store.end()){
                vector<int> temp= {nums[i],nums[j],target};
                sort(temp.begin(),temp.end());
                hashStore.insert(temp);
            }
            store.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(hashStore.begin(),hashStore.end());
    return ans;
}
vector<vector<int>> ThreeSumOptimal(vector<int>& nums){
    //time complexity: n*log(n) + n*n
    //space comlexity O(no of unique triplets) only for returning the answer
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    for(int i=0;i<nums.size()-2 ;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j=i+1;
        int prevJ=j;
        int k= nums.size()-1;
        int prevK=k;
        while(j<k){
            prevJ=j;
            prevK=k;
            if(nums[i]+nums[j]+nums[k]==0){
                result.push_back({nums[i],nums[j],nums[k]});
                while(nums[j]==nums[prevJ] && j<k){
                    j++;
                }
                while(nums[k]==nums[prevK] && j<k){
                    k--;
                }
            }else{
                if(nums[i]+nums[j]+nums[k]<0){
                j++;
                }
                if(nums[i]+nums[j]+nums[k]>0){
                k--;
                }
            }
        }
    }
    return result;
}
int main(){
    vector<int> arr={-1,0,1,2,-1,-4};
    vector<vector<int>> result= ThreeSumOptimal(arr);
    for(auto& it:result){
        for(auto& it2:it){
            cout<<it2<<" , ";
        }
        cout<<endl;
    }

    return 0;
}
