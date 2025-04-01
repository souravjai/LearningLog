class Solution {
public:
    //TC : O(N) SC:O(N+N)
    long long solve(vector<vector<int>>& questions,int index,vector<long long>& dp){
        if(index>=questions.size())
            return 0;

        if(dp[index]!=-1) return dp[index];
        long long take = questions[index][0] + solve(questions,index+questions[index][1]+1,dp);
        long long skip = solve(questions,index+1,dp);
        return dp[index] = max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return solve(questions,0,dp);
    }
};


class Solution {
public:
  //TC: O(N) SC: O(N)
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);

        for(int i = n-1;i>=0;i--){
            int points = questions[i][0];
            int brainpower = questions[i][1];

            long long take = questions[i][0] + dp[ min(i+brainpower+1,n) ];
            long long skip = dp[i+1];
    
            dp[i] = max(take,skip);
        }

        return dp[0];
    }
};
