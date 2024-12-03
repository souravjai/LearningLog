#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int ns = spaces.size();
        int n = s.size();
        for (int i = 0; i < ns; i++)
        {
            s.push_back(' ');
        }

        int idx = ns - 1;
        int end = s.size() - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (idx >= 0 && i + 1 == spaces[idx])
            {
                s[end--] = ' ';
                idx--;
            }
            s[end--] = s[i];
        }
        if (spaces[0] == 0)
            s[0] = ' ';
        return s;
    }
};

/*
TC: O(N)
SC: O(N)
*/
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int idx = 0;
        string ans = "";
        int n = s.size();
        int ns = spaces.size();
        for (int i = 0; i < n; i++)
        {
            if (idx < ns && spaces[idx] == i)
            {
                ans += " ";
                idx++;
            }
            ans += s[i];
        }

        return ans;
    }
};