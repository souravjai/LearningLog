class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        int ans = energy[n-1];

        for(int i = 0;i<n;i++){
            if(i-k>=0){
                energy[i] = max(energy[i],energy[i]+energy[i-k]);
            }
            if(i>=n-k){
                ans = max(ans,energy[i]);
            }
        }

        return ans;
    }
};