package TopInterview150;

/*
TC:O(N)
SC:O(1)
Instead of updating the range, we just figured what is the next range we can reach from i
So we carried the range with l & r thus having a greedy solution
*/

class Solution {
    public int jump(int[] nums) {
        int jumps = 0, l = 0, r = 0, n = nums.length;

        while (r < n - 1) {
            int max = 0;
            for (int i = l; i <= r; i++) {
                max = Math.max(max, nums[i] + i);
            }
            l = r + 1;
            r = max;
            jumps++;
        }

        return jumps;
    }
}

/*
 * TC:O(N^2)SC:O(N)
 */

class Solution_OLD {
    public int jump(int[] nums) {
        int n = nums.length;
        int dp[] = new int[n];

        for (int i = 0; i < n; i++) {

            int jump = nums[i];

            for (int j = 1; i + j < n && j <= jump; j++) {
                dp[i + j] = dp[i + j] == 0 ? dp[i] + 1 : Math.min(dp[i] + 1, dp[i + j]);
            }

            if (i + jump >= n)
                break;
        }
        return dp[n - 1];

    }
}
