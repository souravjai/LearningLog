#include <bits/stdc++.h>
using namespace std;

/*
TC: O(NMlog(MN))
SC: O(NM)
*/

class Solution
{
public:
#define P pair<int, pair<int, int>>
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            P cur = pq.top();
            pq.pop();

            int time = cur.first;
            int i = cur.second.first;
            int j = cur.second.second;

            for (auto dir : dirs)
            {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x >= 0 && x < m && y >= 0 && y < n)
                {
                    if (dp[x][y] == INT_MAX)
                    {
                        if (grid[x][y] <= time + 1)
                        {
                            pq.push({time + 1, {x, y}});
                            dp[x][y] = time + 1;
                        }
                        else
                        {
                            int diff = grid[x][y] - time;
                            int t = diff % 2 != 0 ? grid[x][y] : grid[x][y] + 1;
                            pq.push({t, {x, y}});
                            dp[x][y] = t;
                        }
                    }
                }

                if (x == m - 1 && y == n - 1)
                    return dp[x][y];
            }
        }
        // for(auto i:dp){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m - 1][n - 1];
    }
};

// 0,0 -> 1,1 ->1,2->0,2->0,3->1,3->2,3