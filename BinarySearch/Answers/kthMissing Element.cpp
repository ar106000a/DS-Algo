#include<vector>
#include<iostream>

using namespace std;
int findKthPositive(vector<int>& arr, int k) {
        int number=1;
        int currentIdx=0;
        vector<int> newArr={};
        while(true){
            if(currentIdx==arr.size() || newArr.size()==k){
                break;
            }
            if(arr[currentIdx]==number){
                number++;
                currentIdx++;
            }else{
                newArr.push_back(number);
                number++;
            }
        }
        if(newArr.size()<k){
            cout<<newArr.size()<<endl;
            cout<<k<<endl;
            int arrSize=newArr.size();
            for(int i=0;i<(k-arrSize);i++){
                cout<<"pushing number "<<number<<" to the newArr in the "<<i<<"th iteration"<<endl;
                newArr.push_back(number);
                number++;
            }
        }


        return newArr[k-1];
    }
    int main(){
        vector<int> arr={1,2,3,4};
        int ans= findKthPositive(arr,2);
        cout<<ans<<endl;

    }