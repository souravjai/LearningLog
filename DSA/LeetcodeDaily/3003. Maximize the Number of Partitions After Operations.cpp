class Solution {
public:
    unordered_map<long long, int> dp;

    int solve(string& s, int& k, long long i, long long uniqueChars,
              bool canChange) {
        long long key = (i << 27) | (uniqueChars << 1) | (canChange);

        if (dp.count(key)) {
            return dp[key];
        }

        if (i == s.size()) {
            return 0;
        }

        int result = -1;
        for (int idx = 0; idx < 26; ++idx) {
            if (canChange || idx == s[i] - 'a') {
                int uniqueCharsUpdated = uniqueChars | (1 << idx);
                int uniqueCharCount = __builtin_popcount(uniqueCharsUpdated);
                bool change = idx == s[i] - 'a' ? canChange : false;

                if (uniqueCharCount > k) {
                    result = max(result, 1 + solve(s, k, i + 1, 1 << idx, change));
                } else {
                    result = max(result, solve(s, k, i + 1, uniqueCharsUpdated, change));
                }
            }
        }

        return dp[key] = result;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return solve(s, k, 0, 0, true) + 1;
    }
};
