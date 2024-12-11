/*
* TC: NlogN + 2*N = O(NlogN + 2N)
* SC: O(1)
*/
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;

        while (i < n && j < n)
        {

            while (j < n && nums[j] <= (nums[i] + 2 * k))
            {
                j++;
            }

            ans = max(ans, j - i);
            i++;
        }
        return ans;
    }
};