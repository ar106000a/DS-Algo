#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
vector<int> spiral(vector<vector<int>>& matrix){
    int n= matrix.size();
    int m=matrix[0].size();
    int top=0;
    int bottom=n-1;
    int right=m-1;
    int left=0;

    vector<int> result;
    while(top<=bottom && left<=right ){
        for(int i=left;i<=right ;i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom ;i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left  ;i--){
            result.push_back(matrix[bottom][i]);
        }
    
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            result.push_back(matrix[i][left]);
        }
        left++;
    }

    }
    
    return result;
}

int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> traversal = spiral(matrix);
    for(auto it:traversal){
        cout<<it<<endl;
    }

    return 0;
}
