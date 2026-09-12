#include<iostream>
#include<vector>
using namespace std;
int minDays(vector<int>& bloomDay, int m, int k) {
        int left=INT_MAX;
        int right=1;
        for(int i=0;i<bloomDay.size();i++){
            left=min(left,bloomDay[i]);
            right=max(right,bloomDay[i]);
        }
        int answer=-1;

        while(left<=right){
            int mid=(left+right)/2;
            int count=0;
            int currentCount=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    currentCount++;
                }else{
                    currentCount=0;
                }
                if(currentCount==k){
                    count++;
                    currentCount=0;
                }
            }

            if(count>=m){
                answer=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
            

        }
        return answer;
    }
int main(){
    vector<int> arr={1,10,3,10,2};
    int ans= minDays(arr,3,1);
    cout<<ans<<endl;
}