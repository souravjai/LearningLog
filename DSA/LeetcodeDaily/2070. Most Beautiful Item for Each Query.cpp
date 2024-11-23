#include <bits/stdc++.h>
using namespace std;

/* First solution
* TC: NLOGN + N + KLOGN = O(LogN(N+K))
* SC: N + N = O(N) 
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarySearch(vector<vector<int>> &items, int n, int se)
    {
        int lb = 0, hb = n - 1;
        int ans = -1;

        while (lb <= hb)
        {
            int mid = lb + (hb - lb) / 2;

            if (items[mid][0] <= se)
            {
                ans = items[mid][0];
                lb = mid + 1;
            }
            else
            {
                hb = mid - 1;
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>> &items,
                              vector<int> &queries)
    {
        int n = items.size();

        sort(items.begin(), items.end());

        map<int, int> maximal;
        vector<int> ans;

        int cur_max = 0;
        for (int i = 0; i < n; i++)
        {
            if (maximal.find(items[i][0]) == maximal.end())
            {
                maximal[items[i][0]] = 0;
            }
            cur_max = max(items[i][1], cur_max);
            maximal[items[i][0]] = cur_max;
        }

        for (int query : queries)
        {
            int price = binarySearch(items, n, query);
            if (maximal.find(price) == maximal.end())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(maximal[price]);
            }
        }

        return ans;
    }
};
