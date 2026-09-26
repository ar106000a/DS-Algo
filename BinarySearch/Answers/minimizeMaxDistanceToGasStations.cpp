#include<iostream>
#include<vector>
using namespace std;

long double minimiseMaxDistanceOptimal(vector<int> &arr, int k) {
    long double left=0;
    long double right=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i+1]-arr[i]>right){
            right=arr[i+1]-arr[i];
        }
    }
    double diff= 1e-6;

    // right= 2*right;
    while(right-left>diff){
        long double mid= left + (right-left)/2.0;
        int sum=0;
        for(int i=0;i<arr.size()-1;i++){
            int diff= arr[i+1]-arr[i];
            int required = (diff/mid);
            sum+=required;
        }
        if(sum>k){
            left=mid;
        }else{
            right=mid;
        }
    }
    return (left+right)/2;
}
long double minimiseMaxDistance(vector<int> &arr, int k) {
       vector<long double> distances(arr.size()-1,0);
        for(int i=1; i<=distances.size();i++){
            distances[i-1]=arr[i]-arr[i-1];
        }

        vector<int> filled(arr.size()-1,0);

        for(int i=1;i<=k;i++){
            long double maxGap=-1;
            int maxIndex=-1;
            for(int i=0;i<distances.size();i++){
                long double sectionLength= distances[i]/(filled[i]+1);
                if(sectionLength>maxGap){
                    maxGap=sectionLength;
                    maxIndex=i;
                }
            }
            filled[maxIndex]++;
        }
        long double maxGap=-1;
        for(int i=0;i<distances.size();i++){
            long double sectionLength=distances[i]/(filled[i]+1);
            if(sectionLength>maxGap){
                maxGap=sectionLength;
            }
        }
        return maxGap;
    }
    int main(){
        vector<int> arr={1,2,3,4,5,6,7,8,9,10};
        long double dist= minimiseMaxDistanceOptimal(arr,10);
        cout<<dist<<endl;
    }