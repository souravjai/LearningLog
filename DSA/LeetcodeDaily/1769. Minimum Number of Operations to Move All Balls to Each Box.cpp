
/*
* TC: O(N+N): O(N)
* SC: O(1)
*/
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        int n = boxes.size();

        int leftFactor = 0, leftOnes = 0;
        int rightFactor = 0, rightOnes = 0;

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                rightFactor += i + 1;
                rightOnes++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            rightFactor -= rightOnes;
            ans[i] = leftFactor + rightFactor;
            if (boxes[i] == '1')
            {
                leftOnes++;
                rightOnes--;
            }
            leftFactor += leftOnes;
        }

        return ans;
    }
};