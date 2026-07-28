#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int missingNum(vector<int> &arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
    }
    int n=arr.size()+1;
    int expectedSum= n*(n+1)/2;
    return expectedSum-sum;
}
int main(){
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; 
    int res = missingNum(arr);  
    cout << res << endl;  
    return 0;
}