#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> majorityII(vector<int>& nums){
// We need to understand first , that in an array, the number of elements that occur more than n/3 times will always be 2 or less. Lets say an array of size 8. For it to contain a majority element, the element should appear more than 8/3 times which is 3 times at least. and only 2 such elements can fit in the array of size 8. If we try to assume a 3rd element in such array, the array size must grow to 9, which is incorrect to even assume. So taking this assumption, lets write the bruteforce.

    vector<int> result;
    for(int i=0;i<nums.size();i++){
        if(result.size()==0 || result[0]!=nums[i]){
        int count=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]==nums[i]){
                count++;
            }
        }
        if(count> (nums.size()/3)){
            result.push_back(nums[i]);
        }
        if(result.size()==2){
            break;
        }
    }
    }
    return result;
}

vector<int> majorityIIBetter(vector<int>& nums){
    unordered_map<int,int> temp;
    for(int i=0;i<nums.size();i++){
        temp[nums[i]]++;
    }
    vector<int> res;
    for(auto& it:temp){
        if(it.second>nums.size()/3){
            res.push_back(it.first);
        }
    }
    return res;
}
vector<int> majorityIIOptimal(vector<int>& nums){
    int count1=0;
    int count2=0;
    int el1=0;
    int el2=0;
    for(int i=0;i<nums.size();i++){
        if(count1 == 0 && nums[i]!=el2){
            count1++;
            el1=nums[i];
        }else if(count2==0 && nums[i]!=el1){
            count2++;
            el2=nums[i];
        }else if(nums[i]==el1){
            count1++;
        }else if(nums[i]==el2){
            count2++;
        }else{
            count1--;
            count2--;
        }

    }
    int newCount1=0;
    int newCount2=0;
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==el1){
            newCount1++;
        }
        if(nums[i]==el2){
            newCount2++;
        }
    }
    if(newCount1 > nums.size()/3){
        result.push_back(el1);
    }
    if(newCount2> nums.size()/3 && el1!=el2){
        result.push_back(el2);
    }
    return result;
}
int main(){
    vector<int> arr={0,0,0};
    vector<int> result= majorityIIOptimal(arr);
    for(auto& it:result){
        cout<<it<<endl;
    }

}
