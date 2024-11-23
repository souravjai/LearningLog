package LeetcodeDaily;

import java.util.*;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {

        Map<Integer, Integer> freq = new HashMap<>();
        int repeat = 0, n = nums.length;
        long ans = 0, cur = 0;
        int curNum, curFreq;
        int prevNum, prevFreq;

        for (int i = 0; i < k; i++) {
            curNum = nums[i];
            curFreq = freq.getOrDefault(curNum, 0) + 1;
            freq.put(curNum, curFreq);
            cur += curNum;

            if (curFreq > 1) {
                repeat += 1;
            }
        }

        for (int i = k; i < n; i++) {
            
            if (repeat == 0) {
                ans = Math.max(ans, cur);
            }
            
            curNum = nums[i];
            curFreq = freq.getOrDefault(curNum, 0) + 1;
            freq.put(curNum, curFreq);
            cur += curNum;

            if (curFreq > 1) {
                repeat += 1;
            }

            prevNum = nums[i - k];
            prevFreq = freq.get(prevNum) - 1;
            freq.put(prevNum, prevFreq);
            cur -= prevNum;

            if (prevFreq >= 1) {
                repeat -= 1;
            }

        }

        System.out.println(repeat);
        if(repeat==0){
            ans=Math.max(ans,cur);
        }
        
        return ans;
    }
}