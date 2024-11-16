class Solution {
    public int majorityElement(int[] nums) {
        int ele = -1;
        int freq = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (freq == 0) {
                ele = nums[i];
            }

            if (ele == nums[i]) {
                ++freq;
            } else {
                --freq;
            }
        }

        return ele;
    }
}