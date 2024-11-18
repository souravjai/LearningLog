class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int arr[] = new int[n];
        int window = 0;

        if (k > 0) {

            for (int i = 0; i < k; i++) {
                window += code[(i + 1) % n];
            }

            for (int i = 0; i < n; i++) {
                arr[i] = window;
                window = window - code[(i + 1) % n] + code[(k + i + 1) % n];
            }
        } else if (k < 0) {
            for (int i = k; i < 0; i++) {
                window += code[(n + i) % n];
            }

            for (int i = 0; i < n; i++) {
                arr[i] = window;
                window = window - code[(n + k + i) % n] + code[i];
            }

        }

        return arr;

    }
}