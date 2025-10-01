class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int ans = numBottles;
        while (numBottles + empty >= numExchange) {
            int total = numBottles + empty;
            empty = total % numExchange;
            numBottles = total / numExchange;
            ans += numBottles;
        }

        return ans;
    }
};