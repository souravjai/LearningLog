package DSA.LeetcodeDaily;

import java.util.Arrays;

/* First solution
* TC: NLOGN + KLOGK + K + K  = O( NLogN + KLogK )
* SC: K + K = O(K) + some extra sorting space 
*/

class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {

        int n = items.length, k = queries.length;

        int ans[] = new int[k];
        int qWithIndex[][] = new int[k][2];

        for (int i = 0; i < k; i++) {
            qWithIndex[i][0] = queries[i];
            qWithIndex[i][1] = i;
        }

        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        Arrays.sort(qWithIndex, (a, b) -> a[0] - b[0]);

        int idx = 0;
        int maxBeauty = 0;

        for (int i = 0; i < k; i++) {
            int price = qWithIndex[i][0];

            while (idx < n && items[idx][0] <= price) {
                maxBeauty = Math.max(maxBeauty, items[idx][1]);
                idx++;
            }

            ans[qWithIndex[i][1]] = maxBeauty;
        }
        return ans;
    }
}