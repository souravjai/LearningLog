class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int allXor = 0;
        for (int num : derived)
        {
            allXor ^= num;
        }

        return allXor == 0;
    }
};

/*
[a,b,c] => [a^b,b^c,c^a]
all elmenet must be  ^ to 0
*/