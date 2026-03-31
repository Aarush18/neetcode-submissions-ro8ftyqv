class Solution {
private:
    int solve(int ind , int buy , vector<vector<int>>& dp , vector<int>& prices){
        if(ind >= prices.size()){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        if(buy == 1){
            int take = -prices[ind] + solve(ind + 1 , 0 , dp , prices);
            int skip = solve(ind + 1 , 1 , dp , prices);

            return dp[ind][buy] = max(take , skip);
        }else{
            int sell = prices[ind] + solve(ind + 2 , 1 , dp , prices);
            int skip = solve(ind + 1 , 0 , dp , prices);

            return dp[ind][buy] = max(sell ,skip);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
        return solve(0 , 1 , dp , prices);
    }
};
