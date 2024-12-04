#include<bits/stdc++.h>
using namespace std;

/*
* TC: O(N+M)
* SC: O(1)
*/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(),n2 = str2.size();
        int i = 0,j=0;

        while(i<n1 && j<n2){
            int cur = str1[i];
            int next = str1[i] == 'z' ? 'a':str1[i]+1;

            if(str2[j] == cur || str2[j] == next){
                j++;
            }
            i++;
        }

        return j == n2;
    }
};