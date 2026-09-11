#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int findSecondLargest(vector<int>& nums,int size){
    if(size<2){
        return -1;
    }
    int largest=nums[0];
    int sLargest=INT_MIN;
    for(int i=0;i<size;i++){
        if(nums[i]>largest){
            sLargest=largest;
            largest=nums[i];
        }else if(nums[i]>sLargest && nums[i]<largest){
            sLargest=nums[i];
        }


    }
    return sLargest==INT_MIN?-1:sLargest;
}
int main(){
    vector<int> arr={10,10,10,11};
    int n=arr.size();

    int secondLargest=findSecondLargest(arr,n);
    cout<<"Second Largest element is: "<<secondLargest<<endl;
}