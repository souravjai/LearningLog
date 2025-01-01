
/*
* TC: 
* SC: N*SUM + N (Stack) = O(N * SUM)
*/
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int &num : nums)
            sum += num;

        if (abs(target) > sum)
            return 0;

        unordered_map<int, int> prev, cur;
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            cur.clear();
            for (const auto &[sum, count] : prev)
            {
                cur[sum + nums[i - 1]] += count;
                cur[sum - nums[i - 1]] += count;
            }
            prev = cur;
        }

        return cur[target];
    }
};
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int &num : nums)
            sum += num;

        if (abs(target) > sum)
            return 0;

        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (const auto &[sum, count] : dp[i - 1])
            {
                dp[i][sum + nums[i - 1]] += count;
                dp[i][sum - nums[i - 1]] += count;
            }
        }

        return dp[n][target];
    }
};

class Solution
{
public:
    int sum = 0;
    int solve(vector<int> &nums, int target, int curSum, int index,
              vector<vector<int>> &dp)
    {
        if (nums.size() == index)
        {
            return target == curSum ? 1 : 0;
        }

        if (dp[index][curSum + sum] == -1)
        {
            dp[index][curSum + sum] =
                solve(nums, target, curSum + nums[index], index + 1, dp) +
                solve(nums, target, curSum - nums[index], index + 1, dp);
        }

        return dp[index][curSum + sum];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int n = nums.size();
        for (int num : nums)
            sum += num;

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));

        return solve(nums, target, 0, 0, dp);
    }
};

class Solution
{
public:
    int findWays(vector<int> &nums, int target, int index,
                 vector<unordered_map<int, int>> &dp)
    {
        if (index == nums.size())
        {
            return target == 0 ? 1 : 0;
        }

        if (dp[index].find(target) != dp[index].end())
        {
            return dp[index][target];
        }

        int pickAdd = findWays(nums, target + nums[index], index + 1, dp);
        int pickSub = findWays(nums, target - nums[index], index + 1, dp);

        return dp[index][target] = pickAdd + pickSub;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<unordered_map<int, int>> dp(nums.size());
        return findWays(nums, target, 0, dp);
    }
};