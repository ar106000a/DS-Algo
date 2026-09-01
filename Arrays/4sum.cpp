#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
vector<vector<int>> FourSumBrute(vector<int> &nums, int target)
{
    if (nums.size() < 4)
    {
        return {};
    }
    set<vector<int>> st;

    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            for (int k = j + 1; k < nums.size() - 1; k++)
            {
                for (int l = k + 1; l < nums.size(); l++)
                {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
vector<vector<int>> FourSumBetter(vector<int> &nums, int target)
{
    if (nums.size() < 4)
    {
        return {};
    }
    set<int> hashSt;
    set<vector<int>> st;

    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            hashSt.clear();
            for (int k = j + 1; k < nums.size(); k++)
            {
                int fourth = target - (nums[i] + nums[j] + nums[k]);
                if (hashSt.find(fourth) != hashSt.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSt.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
vector<vector<int>> FourSumOptimal(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int k = 0;
    int l = 0;

    set<vector<int>> st;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            k = j + 1;
            l = nums.size() - 1;
            while (k < l)
            {
                int prevK = k;
                int prevL = l;
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    st.insert({nums[i], nums[j], nums[k], nums[l]});
                    while (nums[l] == nums[prevL] && k < l)
                    {
                        l--;
                    }
                    while (nums[k] == nums[prevK] && k < l)
                    {
                        k++;
                    }
                }
                else if (sum < target)
                {
                    while (nums[k] == nums[prevK] && k < l)
                    {
                        k++;
                    }
                }
                else
                {
                    while (nums[l] == nums[prevL] && k < l)
                    {
                        l--;
                    }
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(),st.end());
    return result;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4, 4, 4, 4, 3, 2, 2, 3};
    vector<vector<int>> result = FourSumOptimal(arr, 2);
    for (auto &it : result)
    {
        for (auto &it2 : it)
        {
            cout << it2 << " , ";
        }
        cout << endl;
    }
}