package LeetcodeDaily;

import java.util.PriorityQueue;

class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(b[0] * a[1], b[1] * a[0]));
        long[] cur;

        int m = quantities.length;
        for (int i = 0; i < m; i++) {
            pq.offer(new long[] { quantities[i], 1 });
        }

        for (int i = 0; i < n - m; i++) {
            cur = pq.poll();
            pq.offer(new long[] { cur[0], cur[1] + 1 });
        }

        cur = pq.poll();
        return (int) Math.ceil((cur[0] * 1.0) / cur[1]);
    }
}