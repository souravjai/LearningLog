class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int asc = 1;
        int desc = 1;
        int ans = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                asc++;
                desc = 1;
            }else if(nums[i]<nums[i-1]){
                desc++;
                asc = 1;
            }else{
                asc=desc=1;
            }
            ans = max(ans,max(asc,desc));
        }
        return ans;
    }
};