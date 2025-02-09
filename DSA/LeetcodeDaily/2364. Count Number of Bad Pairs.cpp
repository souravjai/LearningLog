class Solution
{
public:
    inline long long nC2(int n)
    {
        long long ans = n;
        if (n % 2 == 0)
        {
            ans = ans / 2 * (ans - 1);
        }
        else
        {
            ans = ans * ((ans - 1) / 2);
        }
        return ans;
    }
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i] - i]++;
        }

        long long totalWays = nC2(n);
        long long goodWays = 0;

        for (auto [_, freq] : mp)
        {
            goodWays += nC2(freq);
        }

        return totalWays - goodWays;
    }
};