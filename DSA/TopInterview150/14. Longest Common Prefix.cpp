#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());

        string ans = "";
        int minLen = min(strs[0].size(), strs.back().size());
        for (int i = 0; i < minLen && strs[0][i] == strs.back()[i]; i++)
        {
            ans += strs[0][i];
        }

        return ans;
    }
};