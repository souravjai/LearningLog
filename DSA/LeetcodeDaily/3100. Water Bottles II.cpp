class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottle = numBottles;
        int ans = numBottles;
        numBottles = 0;

        while (emptyBottle >= numExchange) {
            while (emptyBottle >= numExchange) {
                numBottles++;
                emptyBottle -= numExchange;
                numExchange++;
            }
            emptyBottle += numBottles;
            ans += numBottles;
            numBottles = 0;
        }

        return ans;
    }
};