#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(N)
*/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banSet(banned.begin(), banned.end());
        int sum = 0;
        int ans = 0;
        
        for(int i = 1;i<=n;i++){
            if(banSet.find(i)==banSet.end()){
                if(sum+i>maxSum){
                    break;
                }
                sum+=i;
                ans++;
            }
        }

        return ans;
    }
};
