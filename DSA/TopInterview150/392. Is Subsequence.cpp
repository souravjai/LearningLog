#include <bits/stdc++.h>
using namespace std;

//TC:O(N)
//SC: O(1)

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        int ns = s.size(), nt = t.size();

        while (i < ns && j < nt)
        {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return i == ns;
    }
};