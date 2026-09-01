#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=m;i<n+m;i++){
        nums1[i]=nums2[i-m];
       }
       sort(nums1.begin(),nums1.end());
        
    }

void mergeBetter(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int left=0;
        int right=0;
        while(left< m && right<n){
            if(nums1[left]<=nums2[right]){
                result.push_back(nums1[left]);
                left++;
            }else{
                result.push_back(nums2[right]);
                right++;
            }
        }
        while(left<m){
            result.push_back(nums1[left]);
            left++;
        }
        while(right<n){
            result.push_back(nums2[right]);
            right++;
        }

        for(int i=0;i<result.size();i++){
            nums1[i]=result[i];
        }
        
    }
    void mergeOptimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int p2=n-1;
       int p1=m-1;
       int p=m+n-1;
       if(m==0){
        for(int i=0;i<n+m;i++){
            nums1[i]=nums2[i];
        }
        return;
       }
       while(p2>=0 && p1>=0){
        if(nums1[p1]>=nums2[p2]){
            nums1[p]=nums1[p1];
            p1--;
            p--;
        }else{
            nums1[p]=nums2[p2];
            p2--;
            p--;
        }
       }
       while(p2>=0){
        nums1[p]=nums2[p2];
        p2--;
        p--;
       }
      
    }
int main(){

    return 0;
}
