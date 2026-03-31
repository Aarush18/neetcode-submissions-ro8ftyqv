class Solution {
private:
    int solve(int ind , int prev , vector<int>& nums , vector<vector<int>>&dp){
        if(ind >= nums.size()){
            return 0;
        }

        if(dp[ind][prev + 1] != -1){
            return dp[ind][prev + 1];
        }

        int len = 0 + solve(ind + 1 , prev , nums, dp);

        if(prev == -1 || nums[prev] < nums[ind]){
            len = max(len , 1 + solve(ind + 1 , ind , nums,  dp));
        }

        return dp[ind][prev + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size() + 1 , -1));
        return solve(0 , -1 , nums ,dp);
    }
};
