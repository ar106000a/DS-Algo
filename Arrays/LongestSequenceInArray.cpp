#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;
int longestConsecutiveSequenceBetter(vector<int>& nums){
    //THis only works if array is sorted
    if(nums.size()==0){
        return 0;
    }
    int last_smallest=INT_MIN;
    int currentSeq=1;
    int largest=1;
    for(int i=0;i<nums.size();i++){

        if(nums[i]-1==last_smallest){
            last_smallest= nums[i];
            currentSeq++;
            if(largest<currentSeq){
                largest=currentSeq;
            }
        }else if(nums[i]==last_smallest){

        }else{
            currentSeq=1;
            last_smallest= nums[i];
        }
    }
    return largest;

}
int longestConsecutiveSequence(vector<int>& nums){
    //the bruteforce is to simply sort the array and count the length of maximum sequence
    if(nums.size()==0){
        return -1;
    }

     for(int i=0;i<nums.size()-1;i++){
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
    

    int largestConsec=1;
    int largest=1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]+1==nums[i+1]){
            largest++;
            if(largest>largestConsec){
                largestConsec=largest;
                cout<<"assigning "<<largest<<" to largestConsec at index "<<i<<endl;
            }
        }else if(nums[i]==nums[i+1]){

        }else{
            largest=1;
        }
    }
    return largestConsec;
}
int longestConsecutiveSequenceOptimal(vector<int>& nums){
    if(nums.size()==0){
        return 0;
    }
    unordered_set<int> gawk;
    for(int i=0;i<nums.size();i++){
        gawk.insert(nums[i]);
    }
    int largest=1;
    for(auto it:gawk){
        if(gawk.find(it-1)!= gawk.end()){

        }else{
            int currentSeq=1;
            int currentElem=it;
            while(gawk.find(currentElem+1)!=gawk.end()){
                currentSeq++;
                currentElem++;
                largest=max(largest, currentSeq);
            }

        }
    }
    return largest;
}
int main(){
    // vector<int> arr={100,4,200,1,3,2};
    // vector<int> arr={1,0,1,2};
    vector<int> arr={0,0,1,2,3,4,5,6,7,8};
    // 0,0,1,2,3,4,5,6,7,8
    int length= longestConsecutiveSequenceOptimal(arr);
    cout<<length<<endl;
    return 0;
}
