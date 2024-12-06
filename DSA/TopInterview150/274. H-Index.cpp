#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TC:O(NLogN)
    //SC:(1)
    int hIndex(vector<int> &citations)
    {
        int lb = 0, ub = citations.size();
        int ans = 0;
        while (lb <= ub)
        {

            int mid = lb + (ub - lb) / 2;
            int citationCount = 0;

            for (int citation : citations)
            {
                if (citation >= mid)
                    citationCount++;
            }

            if (citationCount >= mid)
            {
                ans = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }

        return ans;
    }
};

class SolutionOLD
{
public:
    //Naive Solution TC:O(N^2) SC:(1)
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int i = 0;

        while (i <= n)
        {
            int citationCount = 0;

            for (int citation : citations)
            {
                if (citation >= i)
                    citationCount++;
            }

            if (citationCount < i)
                break;
            i++;
        }

        return i - 1;
    }
};
