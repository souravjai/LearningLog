class Solution {
public:
    bool isValid(int count[], int k) {
        return count[0] >= k && count[1] >= k && count[2] >= k;
    }
    int takeCharacters(string s, int k) {
        int count[] = {0, 0, 0};
        int n = s.size();
        for (int i = 0;i < n; i++) {
            count[s[i] - 'a']++;
        }

        if (!isValid(count, k))
            return -1;

        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            count[s[j] - 'a']--;

            while (i <= j && !isValid(count, k)) {
                count[s[i] - 'a']++;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return n-ans;
    }
};