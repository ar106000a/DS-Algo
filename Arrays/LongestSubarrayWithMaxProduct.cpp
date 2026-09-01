#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    long long product = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        long long localproduct = 1;
        for (int j = i; j < nums.size(); j++) {
            localproduct *= nums[j];
            product = max(product, localproduct);
        }
    }
    return product;
}
int maxProductOptim(vector<int>& nums) {
    int product = INT_MIN;
    int prefix=1;
    int suffix=1;
    for(int i=0;i<nums.size();i++){
        if(prefix==0){
            prefix=1;
        }

        prefix*= nums[i];
        product=max(prefix,product);
    }
    for(int i=nums.size();i>=0;i--){
        if(suffix==0){
            suffix=1;
        }
        suffix*=nums[i];
        product=max(product,suffix);
    }

    return product;
}

int main() {
    vector<int> arr = {2, -5, 2, 3, -8, -9};
    int product = maxProductOptim(arr);
    cout << product << endl;
    return 0;
}