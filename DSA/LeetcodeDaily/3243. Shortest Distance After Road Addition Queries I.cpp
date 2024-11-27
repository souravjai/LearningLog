#include <bits/stdc++.h>
using namespace std;

//TC: O((N+E)*Q)
//SC: O(N+E)
class Solution
{
public:
    int bfs(vector<vector<int>> graph, int n)
    {
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        int ans = 0;

        while (!q.empty())
        {
            int curNodes = q.size();

            while (curNodes--)
            {
                int cur = q.front();

                if (cur == n)
                    return ans;

                visited[cur] = true;
                q.pop();

                for (int node : graph[cur])
                {
                    if (!visited[node])
                        q.push(node);
                }
            }

            ans++;
        }

        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            graph[i].push_back({i + 1});
        }

        for (vector<int> edge : queries)
        {
            graph[edge[0]].push_back(edge[1]);

            // int ix =0;
            // for(auto x: graph){
            //     cout<<ix<<":";
            //     for(auto y:x){
            //         cout<<y<<" ";
            //     }
            //     cout<<endl;
            //     ix++;
            // }

            // cout<<endl;

            ans.push_back(bfs(graph, n - 1));
        }

        return ans;
    }
};