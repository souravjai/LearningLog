class Solution {
public:

    /*
    TC: m*n + m*n = O(2 M*N)     = O(M*N)
    SC: m+n + m*n+1 = O(M+N+M*N) = O(M*N)
    */
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> row(m,0);
        vector<int> col(n,0);

        vector<pair<int,int>> mp(m*n +1);

        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        
        for(int i = 0 ; i<m*n;i++){
            int r = mp[arr[i]].first;
            int c = mp[arr[i]].second;

            row[r]++;
            col[c]++;

            if(row[r] == n || col[c] == m)
                return i;
        }

        return -1;
    }
};

/*

 [3,2,5]
 [1,4,6]

 m = 2; n=3;
 row = {1 0}
 col = {0 2 0}


*/