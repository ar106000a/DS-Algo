#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>> newMatrix(n,vector<int>(m,0));
        for(int i=0; i<n;i++){
            int col=m-i-1;
            for(int j=0; j<m;j++){
                newMatrix[j][col]= matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               matrix[i][j]= newMatrix[i][j];
            }
        }
    }
void rotateOptimal(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        // vector<vector<int>> newMatrix(n,vector<int>(m,0));
        for(int i=0; i<n;i++){
            for(int j=i+1; j<m;j++){
                int temp= matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]=temp;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<(m/2)+(m%2);j++){
               int temp= matrix[i][j];
               matrix[i][j]= matrix[i][m-1-j];
               matrix[i][m-1-j]=temp;
            }
        }
    }

    int main(){
        vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        rotateOptimal(matrix);
        for(int i=0; i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<< matrix[i][j]<<" , ";
            }
            cout<<endl;
        }
    }