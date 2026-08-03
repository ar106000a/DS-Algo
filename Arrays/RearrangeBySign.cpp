#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
vector<int> rearrangeElements(vector<int>& nums){
   vector<int> pos;
   vector<int> neg;
   for(int i=0;i<nums.size();i++){
    if(nums[i]<0){
        neg.push_back(nums[i]);
    }else{
        pos.push_back(nums[i]);
    }
   }
  
   for(int i=0;i<nums.size();i++){
    if(i%2==0){
        //select from pos
        int n= (i/2);
        nums[i]= pos[n];
    }else{
        //select from neg
        int n= (i/2);
        nums[i]=neg[n];
    }
   }
   return nums;
}
vector<int> rearrangeElementsOptimal(vector<int>& nums){
   vector<int> ans(nums.size());
   int posIdx=0;
   int negIdx=1;
   for(int i=0;i<nums.size();i++){
    if(nums[i]<0){
        ans[negIdx]=nums[i];
        negIdx+=2;
    }else{
        ans[posIdx]=nums[i];
        posIdx+=2;
    }
   }
   return ans;
}
int main(){
    vector<int> arr={3,1,-2,-5,2,-4};
    vector<int> arrangedArr=rearrangeElementsOptimal(arr);
    for( const auto& it:arrangedArr){
        cout<<it<<endl;
    }
    return 0;
}
