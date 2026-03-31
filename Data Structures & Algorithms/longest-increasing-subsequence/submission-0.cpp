class Solution {
private:
    int solve( int ind , int prev_ind , vector<int>& nums , int n , vector<vector<int>>& dp){
        if(ind == n){
            return 0;
        }

        if(dp[ind][prev_ind + 1] != -2){
            return dp[ind][prev_ind + 1];
        }

        int len = 0 + solve(ind + 1 , prev_ind , nums , n , dp);

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len , 1 + solve(ind + 1 , ind , nums , n , dp));
        }

        return dp[ind][prev_ind + 1] = len ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp(nums.size() , vector<int>(nums.size() + 1 , -2));
        return solve(0 , -1 , nums , nums.size(), dp);
    }
};