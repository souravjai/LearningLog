class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> dp(n, 0);

        for (int j = 0; j < m; j++) {
            dp[0] += 1LL * mana[j] * skill[0];

            for (int i = 1; i < n; i++)
                dp[i] = max(dp[i], dp[i - 1]) + 1LL * mana[j] * skill[i];

            for (int i = n - 1; i > 0; i--)
                dp[i - 1] = dp[i] - 1LL * mana[j] * skill[i];
        }
        return dp.back();
    }
};