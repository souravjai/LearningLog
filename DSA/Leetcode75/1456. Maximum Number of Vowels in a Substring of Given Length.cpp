#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/

class Solution
{
public:
    string vowel = "aeiou";
    inline int isVowel(char c)
    {
        return vowel.find(c) == string::npos ? 0 : 1;
    }
    int maxVowels(string s, int k)
    {
        int win = 0;
        int n = s.size();
        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
                ++win;
        }

        int ans = win;

        for (int i = k; i < n; i++)
        {
            win = win + isVowel(s[i]) - isVowel(s[i - k]);
            ans = max(win, ans);
        }

        return ans;
    }
};