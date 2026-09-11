#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        bool fI;
        bool sI;
        bool oI;
        bool eI;
        if (nums[mid] == nums[mid + 1]) {
            fI = true;
            sI = false;
        } else if (nums[mid] == nums[mid - 1]) {
            fI = false;
            sI = true;
        } else if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }

        if (mid % 2 == 1) {
            oI = true;
            eI = false;
        } else {
            oI = false;
            eI = true;
        }

        if (oI && fI) {
            right = mid - 1;
        } else if (oI && sI) {
            left = mid + 1;
        } else if (eI && fI) {
            left = mid + 1;
        } else if (eI && sI) {
            right = mid - 1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr={3,3,7,7,10,11,11};
    int ans= singleNonDuplicate(arr);
    cout<<ans<<endl;
}