class Solution
{
public:
    const int NOT_VISITED = 0;
    const int VISITED = 1;
    const int NOT_TERMINAL = 2;
    const int TERMINAL = 3;

    bool isSafe(int root, vector<int> &dp, vector<vector<int>> &graph)
    {
        if (dp[root] == TERMINAL)
        {
            return true;
        }

        if (dp[root] == VISITED || dp[root] == NOT_TERMINAL)
        {
            return false;
        }

        dp[root] = VISITED;

        for (int node : graph[root])
        {
            if (!isSafe(node, dp, graph))
            {
                dp[node] = dp[root] = NOT_TERMINAL;
                return false;
            }
        }

        dp[root] = TERMINAL;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 0)
            {
                dp[i] = TERMINAL;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (isSafe(i, dp, graph))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// 0 -> Not Visited
// 1-> Visited
// 2-> Terminal
// 3-> Not Terminal

// 0 1 2 3 4
// 3 3 3 3 2
