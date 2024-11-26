#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N+M)
SC: O(N)
*/

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> incoming(n, 0);

        for (vector<int> edge : edges)
        {
            incoming[edge[1]]++;
        }

        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (incoming[i] == 0)
            {
                if (ans != -1)
                    return -1;
                else
                    ans = i;
            }
        }
        return ans;
    }
};