#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int maxSubArr(vector<int>& nums){
    int maxCount=nums[0];
    for(int i=0;i<nums.size();i++){
        int count=nums[i];
        maxCount=max(count,maxCount);
        for(int j=i+1;j<nums.size();j++){
            count+= nums[j];
            if(count>maxCount){
                maxCount=count;
            }
        }
    }
    return maxCount;
}
//The optimal soplution is through Kadane's algorithm which says:
// Take a max=INT_MIN, take a sum=0...
// Iterate through array, add the sum as prefix sum, but the moment sum goes below zero, reset the prefixSum to zero. And if the sum ever exceeds max, update max to be sum, the max at the end, ll be the max sum in an array

int maxSubArrOptimal(vector<int>& nums){
    int sum=0;
    int max=INT_MIN;
    int ansStart=-1;
    int ansEnd=-1;
    int start;

    for(int i=0;i<nums.size();i++){
        if(sum==0){
            start=i;
        }
        sum+=nums[i];
        
        if(sum>max){
            ansEnd=i;
            ansStart=start;
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<nums[i]<<endl;
    }
    return max;
}

int main(){
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3,-4,-4,-3,4,2,5};
    int sum=maxSubArrOptimal(arr);
    cout<<sum<<endl;

    return 0;
}
