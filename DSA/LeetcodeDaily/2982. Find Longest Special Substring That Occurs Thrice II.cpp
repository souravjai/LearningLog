class Solution {
public:
    int maximumLength(string s) {
        map<char,priority_queue<int,vector<int>,greater<int>>> mp;
        int K=3;

        int i = 0, n = s.size();

        while(i<n){
            int j = i;
            while(j<n && s[j]==s[i]){
                j++;
            }

            if(mp.find(s[i])==mp.end()){
                mp[s[i]].push(0);
                mp[s[i]].push(0);
                mp[s[i]].push(0);
            }

            mp[s[i]].push(j-i);
            if(mp[s[i]].size()>K){
                mp[s[i]].pop();
            }
            i=j;
        }


        int ans = 0;

        for(auto i:mp){
            int a = i.second.top();  i.second.pop();
            int b = i.second.top();  i.second.pop();
            int c = i.second.top();  i.second.pop();

            int cur;
            if(a+b+c < 3)            cur = 0;
            else if(a==b && b==c)    cur = a;
            else if(b==c)            cur = b-1;
            else                     cur = max(c-2,b);

            ans = max(ans,cur);
        }

        return ans == 0 ? -1 : ans;

    }
};