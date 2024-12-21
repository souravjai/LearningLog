
/* Had to see 2 Hints before solving it. 
* But I am glad that I was able to come up with the solution after two hints and even code for it
* TC : O(N+M)
* SC: O(N+M) Stack space + Adjacency list Space
*/


class Solution {
public:
    int answer;

    long long dfs( vector<vector<int>>& graph, vector<bool>& visited, vector<int>& values, int k,int root){

        long long sum = 0;
        visited[root] = true;

        for(int i=0;i<graph[root].size();i++){
            if(!visited[graph[root][i]]){
                sum+= dfs(graph,visited,values,k,graph[root][i]);
            }
        }

        sum+= values[root];

        if(sum%k==0){
            answer++;
            sum = 0;
        }
        return sum;
    }


    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n,vector<int>());
        
        for(vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n,false);
        answer = 0;

        dfs(graph,visited,values,k,0);
        return answer;
    }
};