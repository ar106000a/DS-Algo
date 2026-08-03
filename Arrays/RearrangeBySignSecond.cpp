#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
vector<int> rearrangeElements(vector<int>& nums){
   vector<int> pos;
   vector<int> neg;
   for(int i=0;i<nums.size();i++){
    if(nums[i]<0){
        neg.push_back(nums[i]);
    }else{
        pos.push_back(nums[i]);
    }
   }



  if(pos.size()==neg.size()){
   for(int i=0;i<nums.size();i++){
    if(i%2==0){
        //select from pos
        int n= (i/2);
        nums[i]= pos[n];
    }else{
        //select from neg
        int n= (i/2);
        nums[i]=neg[n];
    }
}
    return nums;
    }else if(pos.size()>neg.size()){
        vector<int> ans(neg.size()*2+1);
        for(int i=0;i<neg.size()*2;i++){
            if(i%2==0){
            //select from pos
                int n= (i/2);
                ans[i]= pos[n];
            }else{
            //select from neg
                int n= (i/2);
                ans[i]=neg[n];
        }
   }
            int final=0;
            for(int i=neg.size();i<pos.size();i++){
                final+=pos[i];
            }
            ans[neg.size()*2]=final;
            return ans;
}else{
    vector<int> ans(pos.size()*2+1);
        for(int i=0;i<pos.size()*2;i++){
            if(i%2==0){
            //select from pos
                int n= (i/2);
                ans[i]= pos[n];
            }else{
            //select from neg
                int n= (i/2);
                ans[i]=neg[n];
        }
   }
            int final=0;
            for(int i=pos.size();i<neg.size();i++){
                final+=neg[i];
            }
            ans[pos.size()*2]=final;
            return ans;
}
   return nums;
}

int main(){
    vector<int>  arr={3,1,-2,-5,2,-4,-5,-5,-5};
    vector<int> arrangedArr=rearrangeElements(arr);
    for( const auto& it:arrangedArr){
        cout<<it<<endl;
    }
    return 0;
}
