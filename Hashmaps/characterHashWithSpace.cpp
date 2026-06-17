#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
getline(cin,s);

int hashArr[256]={0};
for(int i=0;i<s.length();i++){
    int code= s[i];
    hashArr[code] +=1;
}

int iterations;
cin>> iterations;
for(int i=0;i<iterations;i++){
    cin>>ws;
    char value;
    cin>> value;
    int index= value ;
    cout<< "Character "<< value<<" occured: " << hashArr[index] << " times" << endl;
}


    return 0;
}