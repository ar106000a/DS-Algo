#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>> arr[i];
    }

    //Cannot hold more than 10e6 size of int arr inside main,
    int hashArr[100000]={0};
    for (int i=0;i<n;i++){
        int number=arr[i];
        hashArr[number]+=1;
    }

    int iterations;
    cin>> iterations;
    for (int i=0;i<iterations;i++){
        int number;
        cin >> number;
        cout << "Number occurs: " << hashArr[number] << " times.";
    }
    return 0;
}