#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0,ans = 0;

        for(int& ele:gain){
            cur+=ele;
            ans=max(ans,cur);
        }

        return ans;
    }
};