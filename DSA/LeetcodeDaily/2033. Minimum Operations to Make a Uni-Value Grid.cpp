class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for(auto it:grid){
            for(auto ele:it)
                arr.push_back(ele);
        }

        sort(arr.begin(),arr.end());

        int ele = arr[arr.size()/2];
        int ans = 0;
        for(int num:arr){
            if(num%x!=ele%x) return -1;
            ans+=abs(num-ele)/x;
        }

        return ans;
    }
};
