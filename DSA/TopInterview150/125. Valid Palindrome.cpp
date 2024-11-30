#include <bits/stdc++.h>
using namespace std;

/* 
TC :O(N)
SC:O(1)
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size();

        while (i < j)
        {
            while (i < j && !iswalnum(s[i]))
                i++;
            while (i < j && !iswalnum(s[j]))
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};