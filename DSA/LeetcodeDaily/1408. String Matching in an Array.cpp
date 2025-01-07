
/*
* TC: O(N^2 + K^2)
* SC: O(1) excluding answer array
*/
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> ans;

        for (string current : words)
        {
            int count = 0;
            for (string word : words)
            {
                if (word.find(current) != string::npos)
                {
                    count++;
                }
            }

            if (count > 1)
            {
                ans.push_back(current);
            }
        }

        return ans;
    }
};