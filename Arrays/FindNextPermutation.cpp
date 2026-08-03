#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// THis is the optimal solution because the brute force in this case ll be as follows: 
// Find all permutations, store them in a vector<vector<int>> and then do a linear search for it in the whole vector to find the next one. We ve found all eprmutations in the other problem through recursion, but for optimal solution we need the following approach
// Start from left and find the element that has some larger element to the right, swap the element with the just-larger element and sort the remaining


void findNextPermutation(vector<int>& nums){
    int firstIdx=-1;
    int secondIdx=-1;
    for(int i=nums.size()-2;i>=0;i--){
        // bool outerBreak=false;
        // for(int j=i;j<nums.size();j++){
        //     if(nums[j]>nums[i]){
        //         firstIdx=i;
        //         secondIdx=j;
        //         outerBreak=true;
        //         break;
        //     }
        // }
        // if(outerBreak){
        //     break;
        // }
        if(nums[i]<nums[i+1]){
            firstIdx=i;
            secondIdx=i+1;
            break;
        }
        
    }
    if(firstIdx!= -1 ){
        for(int i=firstIdx;i<nums.size();i++){
            if(nums[i]>nums[firstIdx] && nums[i]<nums[secondIdx]){
                secondIdx=i;
            }
        }
        cout<< nums[firstIdx]<<endl;
        cout<< nums[secondIdx]<<endl;
        int temp=nums[firstIdx];
        nums[firstIdx]=nums[secondIdx];
        nums[secondIdx]=temp;
    }



    for(int i=firstIdx+1;i<nums.size();i++){
       
        int smallest=nums[i];
        int minIndex=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<smallest){
                minIndex=j;
                smallest=nums[j];
            }
        }
        if(minIndex!=i){
            smallest=nums[minIndex];
            nums[minIndex]=nums[i];
            // cout<< "swapping " << nums[i]<<" with "<<smallest<<endl;
            nums[i]=smallest;
        }
      }
    
}

int main(){
    vector<int> arr={1,2,3};
    findNextPermutation(arr);
    for(const auto& it:arr){
        cout<<it<<endl;

    }
    return 0;
}
