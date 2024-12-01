#include<bits/stdc++.h>
using namespace std;

/*
* TC: O(N)
* SC: N+N : O(N)
*/

class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> mp;

        for(int num:nums){
            if(mp.find(num)!=mp.end())
                return true;

            mp[num*2] = true;
            if(num%2==0) mp[num/2] = true;
        }

        return false;
    }
};