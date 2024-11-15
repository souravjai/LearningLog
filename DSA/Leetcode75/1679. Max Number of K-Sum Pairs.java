import java.util.*;

/*
* TC O()
*
*/

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int currentFreq = mp.getOrDefault(nums[i], 0);
            mp.put(nums[i], currentFreq + 1);
        }

        int ans = 0;
        int allowedThreshold = (int) Math.ceil(k / 2.0);

        for (Map.Entry<Integer, Integer> cur : mp.entrySet()) {
            int key = cur.getKey();
            int value = cur.getValue();

            if (key < allowedThreshold) {
                int compFreq = mp.getOrDefault(k - key, 0);
                ans += Math.min(value, compFreq);
            }
        }

        if (k % 2 == 0) {
            ans += mp.getOrDefault(k / 2, 0) / 2;
        }

        return ans;
    }
}