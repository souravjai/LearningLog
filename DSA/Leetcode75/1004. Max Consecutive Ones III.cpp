#include<bits/stdc++.h>
using namespace std;

// TC: O(N)
// SC: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        while(i<n && k!=0){
            if(nums[i] == 0){
                k--;
            }
            i++;
        }

        int ans = i;
        int st = 0;

        while(i<n){
            if(nums[i]==0){
                while(st<i && nums[st]!=0){
                    st++;
                }
                st++;
            }
            ans = max(ans,i-st+1);
            i++;
        }

        return ans;
    }
};