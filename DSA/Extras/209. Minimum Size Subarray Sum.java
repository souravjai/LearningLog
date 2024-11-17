/*
* TC : N+N : O(N)
* SC: O(1)
*/


class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int win_st = 0, win_en = 0;
        int n = nums.length;
        int ans = n + 1;
        int cur = 0;

        while (win_en < n) {
            cur+=nums[win_en++];

            while(win_st<win_en && cur>=target){
                ans = Math.min(ans,win_en-win_st);
                cur-=nums[win_st++];
            }
        }

        return ans == n+1 ? 0 : ans;
    }
}
