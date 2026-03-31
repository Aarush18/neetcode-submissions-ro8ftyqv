class Solution {
private:
    int solve(int ind , int prevInd , vector<int>& nums , vector<vector<int>>& dp){
        if(ind >= nums.size()){
            return 0;
        }

        if(dp[ind][prevInd + 1] != -1){
            return dp[ind][prevInd + 1];
        }


        int len = 0 + solve(ind + 1 , prevInd , nums , dp);

        if(prevInd == -1 || nums[prevInd] < nums[ind]){
            len = max(len , 1 + solve(ind + 1 ,ind , nums , dp));
        }

        return dp[ind][prevInd + 1] = len;

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));

        return solve(0 , -1 , nums , dp);
    }
};
