#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        int n = nums.size();
        int window = 0;
        for (int i = 0; i < k; i++)
        {
            window += nums[i];
        }
        int ans = window;

        for (int i = k; i < n; i++)
        {
            window = window + nums[i] - nums[i - k];
            ans = max(ans, window);
        }

        return ans * 1.0 / k;
    }
};