#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin >> s;

int hashArr[26]={0};
for(int i=0;i<s.length();i++){
    int code= s[i];
    hashArr[code-97] +=1;
}

int iterations;
cin>> iterations;
for(int i=0;i<iterations;i++){
    cin>>ws;
    char value;
    cin>> value;
    int index= value - 97;
    cout<< "Character occured: " << hashArr[index] << " times" << endl;
}


    return 0;
}