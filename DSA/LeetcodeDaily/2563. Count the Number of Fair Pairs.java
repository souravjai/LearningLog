package DSA.LeetcodeDaily;

import java.util.Arrays;

/*
* TC: NLogN + NLogN = O(NLogN)
* SC: Additional sorting space req
*
*/

class Solution {

    int getLessThatEqualTo(int nums[], int curLower, int lb, int ub) {
        int ans = -1;

        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;

            if (nums[mid] <= curLower) {
                ans = mid;
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
        return ans;
    }

    int getMoreThanEqualTo(int nums[], int curLower, int lb, int ub) {
        int ans = -1;

        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;

            if (nums[mid] >= curLower) {
                ans = mid;
                ub = mid - 1;
            } else {
                lb = mid + 1;
            }
        }
        return ans;
    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        int n = nums.length;
        long ans = 0;

        Arrays.sort(nums);

        for (int i = 0; i < n; i++) {
            int curEle = nums[i];
            int curLower = lower - curEle;
            int curUpper = upper - curEle;

            int li = getMoreThanEqualTo(nums, curLower, i, n - 1);
            int hi = getLessThatEqualTo(nums, curUpper, i, n - 1);

            if (li >= 0 && hi >= 0 && hi >= li) {
                ans += hi - li + 1;
                if (i >= li && i <= hi) {
                    ans -= 1;
                }
            }

        }

        return ans;
    }
}