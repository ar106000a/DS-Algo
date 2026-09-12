#include<vector>
#include<iostream>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
        long long left=1;
        long long right=0;
        for(int i=0;i<piles.size();i++){
            right+=piles[i];
        }
        int speed=right;

        while(left<=right){
            long long mid=(left+right)/2;
            int currentAns=0;
            for(int i=0;i<piles.size();i++){
                int ans= piles[i]/mid;
                if(piles[i]%mid !=0){
                    ans++;
                }
                currentAns+=ans;
            }
            if(currentAns<=h && mid<speed){
                speed=mid;
            }

            if(currentAns<=h ){
                right=mid-1;
            }
            if(currentAns>h){
                left=mid+1;
            }
        }
        return speed;
    }

    int main(){
        vector<int> arr={3,6,7,11};
        int ans= minEatingSpeed(arr,8);
        cout<<ans<<endl;
        return 0;
    }