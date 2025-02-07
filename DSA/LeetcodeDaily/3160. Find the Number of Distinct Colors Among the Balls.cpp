class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> color;
        unordered_map<int, int> colorFreq;

        vector<int> ans;

        for (auto q : queries)
        {
            int ball = q[0];
            int col = q[1];

            int prevColor = color.find(ball) == color.end() ? -1 : color[ball];
            color[ball] = col;

            if (prevColor != -1)
            {
                colorFreq[prevColor]--;
                if (colorFreq[prevColor] == 0)
                {
                    colorFreq.erase(prevColor);
                }
            }
            colorFreq[col]++;

            ans.push_back(colorFreq.size());
        }
        return ans;
    }
};
