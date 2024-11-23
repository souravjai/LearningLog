package LeetcodeDaily;


import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String,Integer> mp = new HashMap<>();
        int n = matrix.length,m=matrix[0].length;
        int ans = 0;
        for(int i = 0;i<n;i++){
            StringBuilder s = new StringBuilder();
            for(int j =0;j<m;j++){
                s.append(matrix[i][0]==matrix[i][j] ? "a":"b");
            }
            

            mp.put(s.toString(),mp.getOrDefault(s.toString(),0)+1);
            ans = Math.max(ans,mp.get(s.toString()));
        }
        return ans;
    }
}

