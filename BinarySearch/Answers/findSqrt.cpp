#include<iostream>

using namespace std;
int floorSqrt(int n) {
        // code here
        int left=1;
        int right= (n/2)+1;
        int answer=1;
        
        while(left<=right){
            int mid= (left+right)/2;
            long long calc=mid*mid;
            if(calc==n){
                return mid;
            }
            if(calc<n){
                answer=mid;
                left=mid+1;
            }
            if(calc>n){
                right=mid-1;
            }
        }
        return answer;
    }
    int main(){
        int ans= floorSqrt(82);
        cout<<ans<<endl;
    }