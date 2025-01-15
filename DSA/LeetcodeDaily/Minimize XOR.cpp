class Solution {
public:
    int bitsCount(int n) {
        int count = 0;
        while (n > 0) {
            n &= n - 1;
            count++;
        }

        return count;
    }
    int minimizeXor(int num1, int num2) {
        int num1_bits = bitsCount(num1);
        int num2_bits = bitsCount(num2);

        if (num1_bits > num2_bits) {
            num2_bits = num1_bits - num2_bits;
            while (num2_bits > 0) {
                num1 = num1 & (num1 - 1);
                num2_bits--;
            }
        }

        else if (num1_bits < num2_bits) {
            num2_bits -= num1_bits;

            while (num2_bits > 0) {
                num1 = num1 | (num1 + 1);
                num2_bits--;
            }
        }

        return num1;
    }
};
// 2
// 3
// 0 1 1 0 0 1
//   1 1 0 0 0