class Solution
{
public:
    const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int colorIsland(vector<vector<int>> &grid, int n, int r, int c,
                    int &islandNumber)
    {
        int size = 1;

        queue<pair<int, int>> q;
        q.push({r, c});

        grid[r][c] = islandNumber;

        while (!q.empty())
        {
            auto [rr, cc] = q.front();
            q.pop();

            for (auto dir : dirs)
            {
                int nr = rr + dir.first;
                int nc = cc + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1)
                {
                    size++;
                    q.push({nr, nc});
                    grid[nr][nc] = islandNumber;
                }
            }
        }
        return size;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int largestIslandSize = 0;

        unordered_map<int, int> islandSize;
        islandSize[0] = 0;

        vector<pair<int, int>> water;

        int color = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int currentIslandSize = colorIsland(grid, n, i, j, color);
                    islandSize[color] = currentIslandSize;
                    largestIslandSize =
                        max(largestIslandSize, currentIslandSize);
                    color++;
                }
                else if (grid[i][j] == 0)
                {
                    water.push_back({i, j});
                }
            }
        }

        for (auto [r, c] : water)
        {
            set<int> connectingIslands;

            for (auto dir : dirs)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n)
                {
                    connectingIslands.insert(grid[nr][nc]);
                }
            }

            int currentSize = 1;
            for (int island : connectingIslands)
            {
                currentSize += islandSize[island];
            }

            largestIslandSize = max(currentSize, largestIslandSize);
        }

        return largestIslandSize;
    }
};