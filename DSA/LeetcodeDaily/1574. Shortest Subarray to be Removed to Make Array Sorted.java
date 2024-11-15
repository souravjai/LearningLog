/*
*
* TC:O(N)
* SC:O(N)
*/

class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {

        int n = arr.length;

        int ans = Integer.MAX_VALUE;
        int j = n - 1, i = 0;

        // Try to find the most sorted with Left
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        }
        ans = Math.min(ans, j);

        if (ans == 0)
            return 0;

        // Try to find by removing middle arrays
        while (j < n) {
            if (arr[i] <= arr[j]) {
                ans = Math.min(ans, j - i - 1);
                if (arr[i] <= arr[i + 1]) {
                    i++;
                } else {
                    break;
                }
            } else {
                j++;
            }
        }

        // Try to find by removing starting array
        while (arr[i] <= arr[i + 1]) {
            i++;
        }

        ans = Math.min(ans, n - i - 1);

        return ans;
    }
}
