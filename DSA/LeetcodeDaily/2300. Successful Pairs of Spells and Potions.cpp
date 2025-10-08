class Solution {
public:
    int lower_bound(vector<int>& potions, int m, int factor,
                    long long success) {
        int ans = m;

        int l = 0, u = m - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            long long midVal = 1LL * potions[mid] * factor;
            if (midVal >= success) {
                ans = mid;
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();

        vector<int> ans;
        for (int spell : spells) {
            int index = lower_bound(potions, m, spell, success);
            ans.push_back(m - index);
        }

        return ans;
    }
};
