class Solution {
private:
    int solve(int target , vector<int> nums , vector<int>& dp){
        int combs = 0 ;
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1){
            return dp[target];
        }

        for(auto num : nums){
            combs += solve(target - num , nums , dp);
        }

        return dp[target] = combs;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1 , -1);
        return solve(target , nums , dp);
    }
};