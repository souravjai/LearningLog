class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int n = prices.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            min = Math.min(min, prices[i]);
            ans = Math.max(ans, prices[i] - min);
        }

        return ans;
    }
}