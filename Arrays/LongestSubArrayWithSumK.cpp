/*
 * ============================================================================
 * TOPIC: Longest Subarray with Sum K
 * ============================================================================
 * 
 * APPROACH 1: Brute Force (longestSubArr)
 * - WHY: Generates every possible subarray by picking a start index (i) 
 *   and expanding the end index (j) to the end of the array.
 * - TIME COMPLEXITY: O(N^2) - Two nested loops.
 * - SPACE COMPLEXITY: O(1) - No extra memory used.
 * - WHEN TO USE: Only for very small arrays or as a baseline logic check.
 * 
 * APPROACH 2: Prefix Sum + Hash Map (longestSubArrBest)
 * - WHY: Uses algebra to find subarrays. If we are at 'runningSum', and we've 
 *   previously seen (runningSum - target), the elements between those two 
 *   points sum exactly to 'target'.
 * - TIME COMPLEXITY: O(N) - Single pass through the array.
 * - SPACE COMPLEXITY: O(N) - Worst case, we store N distinct prefix sums.
 * - WHEN TO USE: This is the mandatory approach when the array contains 
 *   NEGATIVE numbers or ZEROS. 
 * - IMPORTANT FIX NOTE: To get the *longest* length, you should only insert 
 *   prefixSum[runningSum] = i if it DOES NOT already exist in the map. 
 *   Otherwise, zeros/negatives will overwrite the earliest index with a 
 *   later one, shortening your calculated length!
 * 
 * APPROACH 3: Sliding Window / Two Pointers (longestSubArrOptimal)
 * - WHY: Maintains a "window" of valid elements. If the sum is too small, 
 *   expand the window by moving 'right'. If the sum is too big, shrink it 
 *   by moving 'left'.
 * - TIME COMPLEXITY: O(N) - Both 'left' and 'right' pointers only move 
 *   forward. At most, they each traverse the array once (2N operations).
 * - SPACE COMPLEXITY: O(1) - Only integer variables are used.
 * - WHEN TO USE: ONLY when the array has strictly NON-NEGATIVE numbers.
 * - THE CATCH: If there are negative numbers, shrinking the window (moving 
 *   left) might actually *increase* the sum (e.g., subtracting a -5 adds 5). 
 *   This breaks the entire sliding window logic.
 * ============================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int longestSubArr(int arr[],int size,int target){
    int longest=0;
    for(int i=0;i<size;i++){
        int sum=0;
        for (int j=i;j<size;j++){
            sum=sum+arr[j];
            if(sum==target && longest<(j-i+1)){
               longest=(j-i+1);
            }
        }
    }
    return longest;
    
}

int longestSubArrBest(int arr[],int size,int target){
    unordered_map<int,int> prefixSum;
    int runningSum=0;
    int len=0;
    for(int i=0;i<size;i++){
        runningSum+=arr[i];
        if (prefixSum.find(runningSum) == prefixSum.end()) {
    prefixSum[runningSum] = i;
}
        int n= runningSum-target;
        int startingIdx=0;
        if(prefixSum.find(n) != prefixSum.end()){
            startingIdx=prefixSum[n];
            len=max(len,i-startingIdx);
        }
    }
    
    return len;
}

    int longestSubArrOptimal(vector<int> &nums, int k){
        int right=1; int left=0; 
        int sum=nums[0];
        int n=nums.size();
        int len=0;
        while(right<n){
            if(sum<=k){
                if(sum==k){
                    len=max(len,right-left+1);
                }
                right++;
                sum+=nums[right];
            }
            if(sum>k){
                sum-=nums[left];
                left++;
            }
                
        }
        return len;
}

int main(){
    // int arr[3]={-3, 2, 1};
    // int n= longestSubArr(arr,3,6);
    // cout<<"Longest subarray with sum K is of length "<<n<<endl;
    vector<int> arr={3,2,1};
    int n= longestSubArrOptimal(arr,3);
    cout<<"Longest subarray with sum K is of length "<<n<<endl;

    return 0;
}
