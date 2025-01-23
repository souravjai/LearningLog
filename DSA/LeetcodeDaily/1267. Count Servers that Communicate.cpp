class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        const int SERVER = 1;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == SERVER)
                {
                    row[r]++;
                    col[c]++;
                }
            }
        }

        int count = 0;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == SERVER && (row[r] > 1 || col[c] > 1))
                {
                    count++;
                }
            }
        }

        return count;
    }
};