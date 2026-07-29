#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
    void sortColorsBest(vector<int>& nums) {
        int countOne=0;
        int countTwo=0;
        int countZero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                countZero++;
            }
            if(nums[i]==1){
                countOne++;
            }
            if(nums[i]==2){
                countTwo++;
            }
        }
        for(int i=0;i<countZero;i++){
            nums[i]=0;
        }
        for(int i=countZero;i<countZero+countOne;i++){
            nums[i]=1;
        }
        for(int i=countZero+countOne;i<countZero+countOne+countTwo;i++){
            nums[i]=2;
        }
    }
// this was the dutch national flag algorithm: the rule is simple:
// we get 3 variables or pointers, low,mid,high
// in the start, low ll be pointing to 0th index, mid ll be pointing to 0th index, high ll be pointing to last index
// The rules are:
// 0-low-1 will be 0s only
// low-mid-1 will be ones only
// mid-high will be random numbers(1,2,0) , unsorted that we ll sort
// high+1-> n-1 will be 2s only
// Run a loop till mid<=high, if u get a 0 on mid, swap it with low, increment mid and low
// If u get a 1, just increment mid
// If u get a 2, swap it with high and decrement high
// Repeat till mid crosses high
    void sortColorsOptimal(vector<int>& nums){
        int size=nums.size();
        int high=size-1;
        int mid=0;
        int low=0;
        while(mid<=high){
            if(nums[mid]==0){
                int temp=nums[mid];
                nums[mid]=nums[low];
                nums[low]=temp;
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                int temp=nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;
                high--;
            }
        }
    }

int main(){
    vector<int> colors={2,0,1};
    sortColorsOptimal(colors);
    for(const auto& val:colors){
        cout<<val<<endl;
    }

    return 0;
}
