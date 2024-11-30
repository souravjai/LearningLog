#include <bits/stdc++.h>
using namespace std;

/*
* TC: O(E+V)
* SC: O(E+V)
*/

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree;

        for (auto &it : pairs)
        {
            int u = it[0];
            int v = it[1];

            if (adj.find(u) == adj.end())
            {
                adj[u] = vector<int>();
            }
            if (degree.find(u) == degree.end())
            {
                degree[u] = 0;
            }
            if (degree.find(v) == degree.end())
            {
                degree[v] = 0;
            }

            adj[u].push_back(v);
            degree[u]++;
            degree[v]--;
        }

        // for(auto& deg:degree){
        //     cout<<"{"<<deg.first<<":"<<deg.second<<"}, ";
        // }

        int startNode = pairs[0][0];
        for (auto &it : degree)
        {
            if (it.second == 1)
            {
                startNode = it.first;
                break;
            }
        }

        vector<int> path;
        stack<int> st;
        st.push(startNode);

        while (!st.empty())
        {
            int cur = st.top();
            if (adj[cur].size() != 0)
            {
                int edge = adj[cur].back();
                adj[cur].pop_back();
                st.push(edge);
            }
            else
            {
                path.push_back(cur);
                st.pop();
            }
        }

        for (int i = path.size() - 1, idx = 0; i > 0; i--, idx++)
        {
            pairs[idx][0] = path[i];
            pairs[idx][1] = path[i - 1];
        }

        return pairs;
    }
};