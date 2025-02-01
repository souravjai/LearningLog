class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int parity = nums[0]%2;

        for(int num:nums){
            if(num%2!=parity) return false;
            parity = 1 - parity;
        }

        return true;
    }
};