
/*
TC: O(N)
SC: O(1)

This works because it 
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int maxEle = 0;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            maxEle = max(arr[i],maxEle);

            if(maxEle == i){
                answer++;
            }
        }
        return answer;
    }
};

/*
TC: O(N)
SC: O(N)
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n, 0);

        int excess = 0;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            excess++;

            freq[i]--;      // want i
            freq[arr[i]]++; // seen arr[i]

            if (arr[i] == i && freq[i] == 0) {
                excess--;
            } else {
                if (freq[arr[i]] == 0) {
                    excess--;
                }
                if (freq[i] == 0) {
                    excess--;
                }
            }

            if (excess == 0) {
                answer++;
            }
        }

        return answer;
    }
};