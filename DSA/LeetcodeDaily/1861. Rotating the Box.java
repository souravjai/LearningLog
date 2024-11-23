package LeetcodeDaily;

// TC: O(NM)
// SC: O(1) excluding return array which is different structure than input array
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int n = box.length;
        int m = box[0].length;

        for (int i = 0; i < n; i++) {
            int cur = m - 1, space = m - 1;
            while (cur >= 0) {
                if (box[i][cur] == '*') {
                    space = cur - 1;
                } else if (box[i][cur] == '#') {
                    box[i][cur] = '.';
                    box[i][space] = '#';
                    space--;
                }
                cur--;

            }

        }

        char matrix[][] = new char[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = box[n - j - 1][i];
            }
        }

        return matrix;
    }
}