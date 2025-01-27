class Solution {
public:
    bool isPrerequisite(int u,int v,vector<vector<int>>& adj){
        vector<bool> isVisited(adj.size(),false);
        queue<int> q;
        q.push(u);
        isVisited[u] = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int node:adj[cur]){
                if(node==v)  return true;
                if(!isVisited[node]){
                    q.push(node);
                    isVisited[node]=true;
                }
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<bool> ans;

        for(auto& vec: prerequisites){
            adj[vec[0]].push_back(vec[1]);
        }

        for(auto& vec: queries){
            ans.push_back(
                isPrerequisite(
                    vec[0],
                    vec[1],
                    adj
                )
            );
        }

        return ans;
    }
};
