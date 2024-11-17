class Solution {
    private char[] getDigits(int n) {
        return Integer.toString(n).toCharArray();
    }

    public int compress(char[] chars) {

        int start = 0;
        int cur = 0;
        int n = chars.length;

        while (cur < n) {
            char curChar = chars[cur];
            int count = 0;

            while (cur < n && curChar == chars[cur]) {
                cur++;
                count++;
            }

            chars[start++] = curChar;
            if (count == 1)
                continue;

            char digits[] = getDigits(count);
            for (int i = 0; i < digits.length; i++) {
                chars[start++] = digits[i];
            }
        }

        return start;

    }
}