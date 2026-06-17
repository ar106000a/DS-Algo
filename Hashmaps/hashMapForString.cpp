#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    unordered_map<char,int> mpp;
    for(int i=0;i<s.size();i++){
        
       
        //comnpute
mpp[s[i]]+=1;
    }

   
    //map is always ordered in cpp;
    //lets confirm it;
    for(auto it:mpp){
        cout<< it.first << " -> "<<it.second<<endl;
    }

    int iterations;
    cin>>iterations;
    for(int i=0;i<iterations;i++){
        char number;
        cin>>ws>>number;
        //fetch
        cout << "Number " << number << " occured " << mpp[number] <<" times"<<endl;
    }

    return 0;
}