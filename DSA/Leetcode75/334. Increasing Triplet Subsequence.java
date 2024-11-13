package DSA.Leetcode75;



/*
* TC: O(N)
* SC: O(1)
* Only care for minimum and 2nd min
*/


class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        if(n<3) return false;

        int min = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;

        for(int i = 0;i<n;i++){
            if(nums[i]<=min){
                min = nums[i];
            }else if(nums[i]<=min2){
                min2 = nums[i];
            }else if(nums[i]>min2 && nums[i]>min){
                return true;
            }
            
        }

        return false;
    }
}




/*
* TC: O(N)
* SC: O(N)
*/
class Solution1 {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        if (n < 3)
            return false;

        int ascPrefix[] = new int[n];
        int descPrefix[] = new int[n];

        ascPrefix[0] = nums[0];
        descPrefix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            ascPrefix[i] = Math.min(ascPrefix[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            descPrefix[i] = Math.max(descPrefix[i + 1], nums[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > ascPrefix[i - 1] && nums[i] < descPrefix[i + 1]) {
                return true;
            }
        }

        return false;
    }
}