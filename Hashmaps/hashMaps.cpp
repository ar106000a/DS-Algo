#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin>>size;
    int arr[size];
    unordered_map<int,int> mpp;
    for(int i=0;i<size;i++){
        int val;
        cin>>val;
        arr[i]=val;
        //compute
mpp[arr[i]]+=1;
    }
    //Storing and fetching from maps take logN time(N being number of elements in the map)

   
    //map is always ordered in cpp;
    //lets confirm it;
    for(auto it:mpp){
        cout<< it.first << " -> "<<it.second<<endl;
    }

    int iterations;
    cin>>iterations;
    for(int i=0;i<iterations;i++){
        int number;
        cin>>number;
        //fetch
        cout << "Number " << number << " occured " << mpp[number] <<" times"<<endl;
    }

    return 0;
}