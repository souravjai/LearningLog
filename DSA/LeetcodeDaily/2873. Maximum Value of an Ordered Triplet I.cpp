class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int leftMax = 0;
        int maxDiff = 0;
        long long result = 0;

        for(int i = 0;i<nums.size();i++){
            result = max(result, (long long)maxDiff*nums[i]);
            maxDiff = max(maxDiff,leftMax - nums[i]);
            leftMax = max(leftMax,nums[i]);
        }

        return result;
    }
};



