#include <string>
using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        int n = start.size(), m = target.size(), i = 0, j = 0;

        while (i < n && j < m)
        {

            //Get the first L/R in start
            if (start[i] == '_')
            {
                i++;
            }
            //Get the first L/R in target
            if (target[j] == '_')
            {
                j++;
            }

            //if i and j are pointing to L/R
            if (i < n && j < m && start[i] != '_' && target[j] != '_')
            {
                if ((start[i] == 'L' && target[j] == 'L' && i >= j) || (start[i] == 'R' && target[j] == 'R' && i <= j))
                {
                    i++;
                    j++;
                }
                else
                {
                    return false;
                }
            }
        }
        while (i < n)
        {
            if (start[i] != '_')
                return false;
            i++;
        }
        while (j < m)
        {
            if (target[j] != '_')
                return false;
            j++;
        }
        return true;
    }
};