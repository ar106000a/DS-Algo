#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
   void setZeroes(vector<vector<int>>& matrix) {
       int n= matrix.size();
       int m = matrix[0].size();
       if(m==1){
        bool zeroFound=false;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                zeroFound=true;
            }
        }
        if(zeroFound){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        return;
       }
       if(n==1){
        bool zeroFound=false;
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                zeroFound=true;
            }
        }
        if(zeroFound){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        return;
       }
        // cout<<m<<","<<n<<endl;
        // vector<int> cols(m,0);
        // vector<int> rows(n,0);
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    // cols[j]=1;
                    // rows[i]=1;
                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0=0;
                    }
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                // if(cols[j]==1 || rows[i]==1){
                //     matrix[i][j]=0;
                // }
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=1;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        

        
    }
int main(){
    vector<vector<int>> arr={{1,2,3},{4,0,6},{7,8,9}};
    setZeroes(arr);
    for(auto it:arr){
        for(auto it2:it){
            cout<< it2 << ", ";
        }
        cout<<endl;
    }
    return 0;
}
