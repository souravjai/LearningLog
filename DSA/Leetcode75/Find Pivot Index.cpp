#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        int prefix = 0;
        int n = nums.size();

        for (int &num : nums)
        {
            sum += num;
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix == sum - (prefix + nums[i]))
            {
                return i;
            }
            prefix += nums[i];
        }

        return -1;
    }
};