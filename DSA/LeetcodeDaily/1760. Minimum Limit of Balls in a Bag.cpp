#include <bits/stdc++.h>
using namespace std;

/*
* TC: O(N Log K)
* SC: O(1)
*/

class Solution
{
public:
    bool isPossible(vector<int> &nums, int penalty, int maxOp)
    {
        int bagIdx = 0;
        for (int num : nums)
        {
            int curBag = ceil(num / (double)penalty) - 1;
            bagIdx += curBag;

            if (bagIdx > maxOp)
                return false;
        }

        return true;
    }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int maxEle = nums[0];
        for (int num : nums)
        {
            maxEle = max(num, maxEle);
        }
        int ans = maxEle;
        int lb = 1, ub = maxEle;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;
            if (isPossible(nums, mid, maxOperations))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        return ans;
    }
};
