/*
* TC O(N*logK(N))
* SC O(N)
*/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        long long ans = 0;

        while(k>0){
            int cur = pq.top();
            pq.pop();

            pq.push(floor(sqrt(cur)));
            k--;
        }

        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }   

        return ans;
    }
};