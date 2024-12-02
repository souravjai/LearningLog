#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int i = 0;
        int n = sentence.size();
        int m = searchWord.size();
        int ans = 1;
        bool flag = false;
        while (i < n)
        {
            int k = 0;

            while (i < n && k < m && sentence[i] == searchWord[k])
            {
                i++;
                k++;
            }

            if (k == m)
            {
                flag = true;
                break;
            }

            while (i < n && sentence[i] != ' ')
            {
                i++;
            }

            i++;
            ans++;
        }

        return flag ? ans : -1;
    }
};