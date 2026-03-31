class Solution {
private:
    int solve(int ind , vector<int>& nums , vector<int>& dp){

        if(ind >= nums.size()){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int pick = nums[ind] + solve(ind + 2 , nums , dp);
        int notPick = solve(ind + 1 , nums , dp);

        return dp[ind] = max(pick , notPick);

    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() + 1 , -1);
        return solve(0 , nums , dp);
    }
};
