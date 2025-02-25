class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int even = 1;
        int odd = 0;
        int sum = 0;
        int MOD=1e9+7;
        for(int num:arr){
            sum+=num;
            if(sum%2==0){
                even++;
                ans+=odd;
            }else{
                odd++;
                ans+=even;
            }
            ans%=MOD;
        }

        return ans;
    }
};
