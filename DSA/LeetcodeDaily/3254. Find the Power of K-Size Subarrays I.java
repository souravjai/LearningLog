class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int cons_prefix[] = new int[n];
        int ans[] = new int[n-k+1];

        cons_prefix[0] = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i-1]+1 == nums[i])
                cons_prefix[i] = cons_prefix[i-1]+1;
            else
                cons_prefix[i] = 1;
        }


        for(int i=0;i<n-k+1;i++){
            ans[i] = cons_prefix[k-1+i] >= k ? nums[k-1+i] : -1;
        }

        return ans;
    }
}