#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnique(unordered_set<int> &nums, unordered_set<int> st)
    {
        vector<int> ans;

        for (int num : nums)
        {
            if (st.find(num) == st.end())
                ans.push_back(num);
        }

        return ans;
    }

    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set setNums1(nums1.begin(), nums1.end());
        unordered_set setNums2(nums2.begin(), nums2.end());

        return {
            findUnique(setNums1, setNums2),
            findUnique(setNums2, setNums1),
        };
    }
};