#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N+Q)
SC: O(N+Q)
*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> parity(nums.size(),0);
        vector<bool> ans;

        for(int i = 1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                parity[i] = parity[i-1]+1;
            }else{
                parity[i] = parity[i-1];
            }
        }

        
        for(auto& i:queries){
            ans.push_back(parity[i[0]]==parity[i[1]]);
        }
        return ans;
    }
};