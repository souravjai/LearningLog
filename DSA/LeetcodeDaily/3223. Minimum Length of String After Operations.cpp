class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};
        int answer = 0;
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                answer += freq[i] % 2 == 0 ? 2 : 1;
            }
        }

        return answer;
    }
};