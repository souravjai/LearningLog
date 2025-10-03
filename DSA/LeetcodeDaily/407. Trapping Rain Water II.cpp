#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, m;
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    bool isValid(int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        n = heightMap.size();
        m = heightMap[0].size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int waterTrapped = 0;

        for (int j = 0; j < m; j++) {
            for (int i : {0, n-1}) {
                if (!isVisited[i][j]) {
                    pq.push({heightMap[i][j], {i, j}});
                    isVisited[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j : {0, m-1}) {
                if (!isVisited[i][j]) {
                    pq.push({heightMap[i][j], {i, j}});
                    isVisited[i][j] = true;
                }
            }
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int height = top.first;
            int r = top.second.first;
            int c = top.second.second;

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (isValid(nr, nc) && !isVisited[nr][nc]) {
                    int nHeight = heightMap[nr][nc];
                    waterTrapped += max(0, height - nHeight);
                    pq.push({max(height, nHeight), {nr, nc}});

                    isVisited[nr][nc] = true;
                }
            }
        }

        return waterTrapped;
    }
};