#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
long long ncr(int n, int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int getPascalElement(int numrow, int numcol){
    return ncr(numrow,numcol);
}
vector<int> getPascalRow(int numRow){
    vector<int> result;
    for(int i=0;i<numRow+1;i++){
        int elem= ncr(numRow,i);
        result.push_back(elem);
    }
    return result;
}

vector<vector<int>> getPascalTriangle(int numRow){
    vector<vector<int>> result;
    for(int i=0;i<numRow;i++){
        vector<int> secRes;
        for(int j=0;j<i+1;j++){
            int elem= ncr(i,j);
            secRes.push_back(elem);
        }
        result.push_back(secRes);
        secRes.clear();
    }
    return result;
}
int main(){
    // int elem= getPascalElement(5,3);
    // cout<<elem<<endl;

    // vector<int> res= getPascalRow(4);
    // for(auto& it:res){
    //     cout<<it<<endl;
    // }

    vector<vector<int>> result= getPascalTriangle(6);
    for(auto& it:result){
        for(auto& it2:it){
            cout<<it2<<" , ";
        }
        cout<<endl;
    }
    return 0;
}
