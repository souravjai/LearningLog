#include<bits/stdc++.h>
using namespace std;

/*
    After each k right rotation array will come back to orignal place: K%=n;
    Now 
    K=0 [0,1,2,3] -> [0,1,2,3]   Note reverse array = [3,2,1,0]
    K=1 [0,1,2,3] -> [3,0,1,2]   Note [3] [0,1,2] 
    K=2 [0,1,2,3] -> [2,3,0,1]   Note [2,3] [0,1]
    K=3 [0,1,2,3] -> [1,2,3,0]   Note [1,2,3] [0] ; this partition are reverse of reverse array

    So we just want to:
    (i)   reverse[0...n-1]
    (ii)  reverse[0...k-1]
    (iii) reverse[k...n-1]

    TC:O(N)
    SC:O(1)
*/

class Solution {
public:
    void reverse(vector<int>& nums,int from,int to){
        int n = to-from+1;
        for(int i = 0;i<n/2;i++){
            int temp = nums[i+from];
            nums[i+from] = nums[to-i];
            nums[to-i] = temp;
        }

    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
    
        //Reverse 0...N
        reverse(nums,0,n-1);
        cout<<"0..N Done";
        //Reverse 0...K
        reverse(nums,0,k-1);
        cout<<"0..K Done";

        //Reverse K+1...N
        reverse(nums,k,n-1);
        cout<<"K..N Done";
        
    }
};