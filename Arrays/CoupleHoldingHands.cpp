#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int coupleHoldingHands(vector<int>& nums){
    int n=nums.size();
    vector<int> pos(2*n);
    int swap=0;
    for(int i=0;i<nums.size();i++){
        pos[nums[i]]=i;
    }

    for(int i=0;i<nums.size();i+=2){
        if((nums[i]^1) != nums[i+1]){
            int targetIndex= pos[(nums[i]^1)];
            int impostor= nums[i+1];
            int temp= nums[targetIndex];
            nums[targetIndex]=nums[i+1];
            nums[i+1]=temp;
            pos[nums[i]^1]=i+1;
            pos[impostor]=targetIndex;
            swap++;
        }
    }
    return swap;
}
int main(){
    vector<int> arr={0,2,4,6,7,1,3,5};
    int swaps= coupleHoldingHands(arr);
    cout<<swaps<<endl;
    return 0;

}