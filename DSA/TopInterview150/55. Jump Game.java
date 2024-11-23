package TopInterview150;

/*
TC: O(N)
SC: O(1)
*/

class Solution {
    public boolean canJump(int[] nums) {
        int maxReach = nums[0];

        for (int i = 0; i < nums.length; i++) {
            if (i > maxReach)
                return false;
            maxReach = Math.max(maxReach, nums[i] + i);
        }

        return true;
    }
}
