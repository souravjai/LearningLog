package LeetcodeDaily;

/*
TC: O(NM)
SC: O(1)
*/

class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long absoluteSum = 0;
        int negativeCount = 0;
        int minimumEle = Integer.MAX_VALUE;

        int n = matrix.length, m = matrix[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                absoluteSum += Math.abs(matrix[i][j]);
                minimumEle = Math.min(minimumEle, Math.abs(matrix[i][j]));

                if (matrix[i][j] < 0) {
                    negativeCount++;
                }
            }
        }
        if (negativeCount % 2 != 0) {
            absoluteSum -= 2 * minimumEle;
        }

        return absoluteSum;
    }
}