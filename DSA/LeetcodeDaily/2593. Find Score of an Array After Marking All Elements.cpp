/*
TC: O(NLogN)
SC: O(N)
*/

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        while (!pq.empty())
        {
            int index = pq.top().second;
            pq.pop();
            if (nums[index] != 0)
            {
                ans += nums[index];

                nums[index] = 0;
                if (index - 1 >= 0)
                    nums[index - 1] = 0;
                if (index + 1 <= n - 1)
                    nums[index + 1] = 0;
            }
        }

        return ans;
    }
};