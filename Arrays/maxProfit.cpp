 #include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



 
 int maxProfit(vector<int>& nums){
        int minimal=nums[0];
        int minimalIdx=0;
        int profit=0;
        for(int i=1;i<nums.size();i++){
            profit=max(profit, nums[i]-minimal);
            if(nums[i]<minimal){
                minimal=nums[i];
                minimalIdx=i;
            }
        }
        return profit;
    }

    int main(){
        vector<int> arr={7,1,5,3,6,4};
        int profit= maxProfit(arr);
        cout<<profit<<endl;
    return 0;
}