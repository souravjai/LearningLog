class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = 1;
        int cur = 1;

        int ans = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, max(cur / 2, min(cur, prev)));
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }

        return max(ans, max(cur / 2, min(cur, prev)));
    }
};