#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>


using namespace std;
int majorityElem(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        int count=0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]==nums[i]){
                count++;
            }
        }
        if(count>nums.size()/2){
            return nums[i];
        }
    }
    return -1;
}
int majorityElemBetter(vector<int>& nums)
{
    map<int,int> temp;
    for(int i=0;i<nums.size();i++){
        temp[nums[i]]++;
    }
    for(auto it:temp){
        if(it.second>nums.size()/2){
            return it.first;
        }
    }
    return -1;
}

//Now we ll even optiize it using the Moore's voting algorithm
// The algorithm says to do the following:
// The algorithm takes first element as the majority element, then iterates over and keeps track of a count variable. If it finds next element equal to majority element, it increments the count, if it doesnt, it decrements the count. If at any point , count hits zero, it resets the majority element as the next one. In the end, check if the count is greater than n/2, u ve got the majority element, lets code it
int majorityElemOptimal(vector<int>& nums){
    int majorityElement=nums[0];
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(count==0){
            majorityElement=nums[i];
        }
        if(nums[i]==majorityElement){
            count++;
        }else{
            count--;
        }
    }
    int newCount=0;
   for(int i=0;i<nums.size();i++){
    if(nums[i]==majorityElement){
        newCount++;
    }

   }
   if(newCount>nums.size()/2){
    return majorityElement;
   }
   return -1;
}
int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    int count=majorityElemOptimal(arr);
    cout<<count<<endl;
    return 0;
}
