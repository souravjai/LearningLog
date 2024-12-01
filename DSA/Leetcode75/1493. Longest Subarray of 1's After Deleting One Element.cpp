#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int st = 0, n = nums.size();
        int ans = 0;
        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            zeroCount += nums[i] == 0 ? 1 : 0;

            while (zeroCount > 1)
            {
                zeroCount -= nums[st] == 0 ? 1 : 0;
                st++;
            }
            ans = max(ans, i - st);
        }

        return ans;
    }
};

// 0 1 1 1 0 1 1 0 1
// 0 1 2 3 4 5 6 7 8

class SolutionOLD
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        bool flag = true;

        while (j < n && (nums[j] != 0 || flag))
        {
            if (nums[j] == 0)
                flag = false;
            j++;
        }

        ans = j;
        while (j < n)
        {
            //set window start
            while (i < j && nums[i] != 0)
            {
                i++;
            }
            i++;
            j++;
            //set window end
            while (j < n && nums[j] != 0)
            {
                j++;
            }
            ans = max(ans, j - i);
        }

        return ans - 1;
    }
};

// 0 1 1 1 0 1 1 0 1
// 0 1 2 3 4 5 6 7 8