class Solution {
private:
    int solve(int ind , vector<int>& dp , int n , vector<int>& nums){
        if(ind >= n ){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int pick = nums[ind] + solve(ind + 2, dp , n , nums);
        int notPick = solve(ind + 1 , dp , n , nums);

        return dp[ind] = max(pick , notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1 , -1);

        return solve(0 , dp , n , nums);
    }
};
