class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long right = 0;
        long long left = 0;
        long long ans = LLONG_MAX;

        for (int& ele : grid[0]) {
            right += ele;
        }

        for (int i = 0; i < n; i++) {
            right -= grid[0][i];
            ans = min(ans, max(right, left));
            left += grid[1][i];
        }

        return ans;
    }
};