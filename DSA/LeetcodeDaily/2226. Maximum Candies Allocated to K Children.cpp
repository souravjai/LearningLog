class Solution {
public:
    int canDistributeCandies(vector<int>& candies,int candyCount,long long k){ //O(N)
        for(int candy:candies){
            k-= candy/candyCount;
            if(k<=0) return true;
        }
        cout<<endl;
        return false;
    }
    int getMaximumCandyPile(vector<int>& candies){  //O(N)
        int maximum = INT_MIN;
        for(int candy:candies){
            maximum = max(maximum,candy);
        }
        return maximum;
    }
    int maximumCandies(vector<int>& candies, long long k) { //O(N+NLogN)-> O(NLogN)
        int lb = 1;
        int ub = getMaximumCandyPile(candies); //O(N)
        int ans = 0;

        //O(logN * N)
        while(lb<=ub){
            int mid = lb + (ub - lb)/2;

            if(canDistributeCandies(candies,mid,k)){ //O(N)
                ans = mid;
                lb = mid+1;
            }else{
                ub = mid-1;
            }
        }

        return ans;
    }
};
