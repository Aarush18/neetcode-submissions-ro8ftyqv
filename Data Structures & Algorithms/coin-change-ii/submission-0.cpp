class Solution {
private:
    int solve( int ind , int target , vector<int>& coins , vector<vector<int>>& dp){
        if(target == 0){
            return 1;
        }
        if(target < 0 || ind == coins.size()){
            return 0;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        int take = 0;
        if(target >= coins[ind]){
            take = solve(ind , target - coins[ind] , coins , dp);
        }
        int skip = solve(ind + 1 , target , coins , dp);

        return dp[ind][target] = take + skip;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size() , vector<int>(amount + 1 , -1));
        int ans = solve(0 , amount , coins , dp);
        return ans;
    }
};
