class Solution {
private:
    int solve(vector<int>& cost , vector<int>& dp , int ind  , int n ){
        
        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int take1 =  cost [ind] + solve(cost , dp , ind + 1 , n);
        int take2 = cost[ind] + solve(cost , dp , ind + 2 , n);

        return dp[ind] = min(take1 , take2);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1 , -1);
        return min(solve(cost , dp , 0 , n) , solve(cost , dp , 1 , n));
    }
};
