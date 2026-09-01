#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int countSubarraysWithXORK(vector<int>& nums, int target){
    unordered_map<int,int> prefixXor;
    prefixXor[0]=1;
    int runningXOR=0;
    int total=0;
    for(int i=0;i<nums.size();i++){
        runningXOR= runningXOR^nums[i];
        int n = runningXOR^target;
        if(prefixXor.find(n)!= prefixXor.end()){
            int value=prefixXor[n];
            total+=value;
        }

        prefixXor[runningXOR]++;
    }
    return total;
}
int main(){
    vector<int> arr={4,2,2,6,4};
    int count= countSubarraysWithXORK(arr,6);
    cout<<count<<endl;
    return 0;
}