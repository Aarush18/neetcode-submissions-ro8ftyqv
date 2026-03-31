class Solution {
private:
    int solve(int ind , vector<int>& coins , vector<vector<int>>& dp , int target , int n){
        if(target == 0){
            return 0;
        }
        if(ind == n){
            return 1e9;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        int take = 1e9 ;
        if(target >= coins[ind]){
         take = 1 + solve(ind  , coins , dp , target - coins[ind] , n);
        }
        int notTake = solve(ind + 1 , coins , dp , target , n);

        return dp[ind][target] = min(take , notTake);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1 , vector<int>(amount + 1, -1));
        int ans = solve(0, coins, dp, amount ,  coins.size());
        return (ans >= 1e9 ? -1 : ans);
    }
};
