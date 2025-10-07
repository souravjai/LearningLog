class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& d : dirs) {
            int r = i + d.first;
            int c = j + d.second;

            if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] ||
                heights[r][c] < heights[i][j])
                continue;

            dfs(r, c, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
            dfs(m - 1, j, heights, atlantic);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};  