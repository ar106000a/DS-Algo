#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> hashie;
        int size= grid.size()*grid[0].size();
        vector<bool> presence(size+1, false);
        int repeating;
        int missing;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                    hashie[grid[i][j]]++;
                    if(hashie[grid[i][j]]>1){
                        repeating=grid[i][j];
                    }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(hashie.find(grid[i][j])!=hashie.end()){
                    presence[grid[i][j]]=true;
                }
            }
        }
        for(int i=1;i<presence.size();i++){
            if(presence[i]==false){
                missing=i;
            }
        }
        return {repeating,missing};

    }
    