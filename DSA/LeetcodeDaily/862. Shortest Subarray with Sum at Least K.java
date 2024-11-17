/*
* TC: O(NlogN)
* SC: O(N)
*/
class Pair {
    public long sum;
    public int index;

    Pair(long sum, int index) {
        this.sum = sum;
        this.index = index;
    }
}

class Solution1 {
    public int shortestSubarray(int[] nums, int k) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.sum, b.sum));
        int n = nums.length;
        int ans = n + 1;
        long psum = 0;
        for (int i = 0; i < n; i++) {
            psum += nums[i];

            if (psum >= k)
                ans = Math.min(ans, i + 1);

            while (!pq.isEmpty() && psum - pq.peek().sum >= k) {
                ans = Math.min(ans, i - pq.poll().index );
            }

            pq.offer(new Pair(psum,i));
        }

        return ans == n + 1 ? -1 : ans;
    }
}