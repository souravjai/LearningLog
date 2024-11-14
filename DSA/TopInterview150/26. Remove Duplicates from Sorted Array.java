package DSA.TopInterview150;

class Solution {
    public int removeDuplicates(int[] nums) {

        int start_ind = 0;
        int n = nums.length;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[start_ind++] = nums[i - 1];
            }
        }
        nums[start_ind++] = nums[n - 1];

        return start_ind;
    }
}