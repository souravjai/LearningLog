class Solution {
private:
    int n, m;
    const int RIGHT = 1;
    const int LEFT = 2;
    const int DOWN = 3;
    const int UP = 4;

    bool isValid(int r,int c){
        return r>=0 && r<n && c>=0 && c<m;
    }

public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> isVisited(n,vector<bool>(m, false));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int r = top.second.first;
            int c = top.second.second;

            if (r == n - 1 && c == m - 1)
                return cost;
            
            if(isVisited[r][c]) continue;

            isVisited[r][c] = true;
            // left
            if (isValid(r, c - 1) && !isVisited[r][c - 1]) {
                int routeCost = grid[r][c] == LEFT ? 0 : 1;
                pq.push({cost + routeCost, {r, c - 1}});
            }
            // Right
            if (isValid(r, c + 1) && !isVisited[r][c + 1]) {
                int routeCost = grid[r][c] == RIGHT ? 0 : 1;
                pq.push({cost + routeCost, {r, c + 1}});
            }
            // UP
            if (isValid(r - 1, c) && !isVisited[r - 1][c]) {
                int routeCost = grid[r][c] == UP ? 0 : 1;
                pq.push({cost + routeCost, {r - 1, c}});
            }
            // DOWN
            if (isValid(r + 1, c) && !isVisited[r + 1][c]) {
                int routeCost = grid[r][c] == DOWN ? 0 : 1;
                pq.push({cost + routeCost, {r + 1, c}});
            }
        }

        return -1;
    }
};