class Solution {
    public void moveZeroes(int[] nums) {
        int st = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[st++] = nums[i];
            }
        }

        while (st < n) {
            nums[st++] = 0;
        }
    }
}public class 283. Move Zeroes {
    
}
