package Leetcode75;

/*
TC: O(N)
SC: O(1)
*/

class Solution {
    public int maxArea(int[] height) {
        int start = 0, end = height.length - 1, ans = 0;

        while (start < end) {
            ans = Math.max(ans, (end - start) * Math.min(height[end], height[start]));

            if (height[start] < height[end])
                start++;
            else
                end--;
        }

        return ans;
    }
}

/*
 * 1 8 6 2 5 4 8 3 7
 * 
 * 1 8 8 8 8 8 8 8 8
 * 8 8 8 8 8 8 8 7 7
 * 
 * 0 1 1 1 1 1 1 1 1
 * 6 6 6 6 6 6 6 8 8
 * 
 * 1 8 8 8 8 8 8 7 7
 * 6 5 5 5 5 5 5 7 7
 */