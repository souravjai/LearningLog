/*
TC: O(MN)
SC: O(MN)
*/

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {

        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int, int>> bfs;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    bfs.push({i, j});
                    isWater[i][j] = 0;
                }
                else
                {
                    isWater[i][j] = -1;
                }
            }
        }

        int level = 0;
        while (!bfs.empty())
        {
            int size = bfs.size();
            level++;

            for (int i = 0; i < size; i++)
            {
                auto cur = bfs.front();
                bfs.pop();

                int r = cur.first;
                int c = cur.second;

                for (auto dir : dirs)
                {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        isWater[nr][nc] == -1)
                    {
                        isWater[nr][nc] = level;
                        bfs.push({nr, nc});
                    }
                }
            }
        }

        return isWater;
    }
};