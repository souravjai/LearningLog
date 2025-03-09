class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int bad = 0;
        int n = colors.size();
        for (int i = 1; i < k; i++) {
            if (colors[i] == colors[i - 1]) {
                bad++;
            }
        }
        int ans = bad == 0 ? 1 : 0;
        

        for(int i = 0;i<n-1;i++){
            if(colors[i]==colors[i+1]){
                bad--;
            }

            if(colors[(i+k)%n] == colors[(i+k-1)%n]){
                bad++;
            }

            ans+= bad == 0 ? 1 : 0;
        }

        return ans;
    }
};
