#include <bits/stdc++.h>
using namespace std;

/*
TC: O(N)
SC: O(1)
*/
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> ransom(26, 0), mag(26, 0);

        for (char &letter : ransomNote)
        {
            ransom[letter - 'a']++;
        }

        for (char &letter : magazine)
        {
            mag[letter - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (mag[i] < ransom[i])
                return false;
        }
        return true;
    }
};