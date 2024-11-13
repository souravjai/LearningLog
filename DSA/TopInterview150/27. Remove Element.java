package DSA.TopInterview150;

class Solution {
    public int removeElement(int[] nums, int val) {
        int st = 0;
        int end = nums.length - 1;

        while (st <= end) {
            if (nums[st] == val) {
                nums[st] = nums[end];
                end--;
            } else {
                st++;
            }
        }
        return st;
    }
}