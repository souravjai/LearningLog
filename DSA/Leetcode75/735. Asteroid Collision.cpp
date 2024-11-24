class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            int n = asteroids.size();
    
            vector<int> ans;
    
            for(int i =0;i<n;i++){
                int cur = asteroids[i];
                while(ans.size()!=0 && ans.back()>0 && cur<0){
                    if(ans.back()<abs(cur)){
                        ans.pop_back();
                    }else if(ans.back()==abs(cur)){
                        ans.pop_back();
                        cur=0;
                    }else{
                        cur=0;
                    }
                }
                if(cur!=0) ans.push_back(cur);
            }
            return ans;
        }
    };