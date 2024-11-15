package DSA.TopInterview150;

class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if (n < 2) {
            return n;
        }

        int prev2 = nums[0];
        int prev1 = nums[1];
        int start = 2;

        for (int i = 2; i < n; i++) {
            if (nums[i] != prev1 || nums[i] != prev2) {
                nums[start++] = nums[i];
            }

            prev2 = prev1;
            prev1 = nums[i];
        }

        return start;
    }
}