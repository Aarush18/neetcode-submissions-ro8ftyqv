class Solution {
private:
    bool solve(int ind , vector<int>& nums , vector<int>& dp){
        if(ind >= nums.size() - 1){
            return true;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        for(int jump = 1 ; jump <= nums[ind]; jump++){
            if(solve(ind + jump , nums , dp) == true){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1){
            return true;
        }

        vector<int> dp(nums.size() + 1 , -1);

        return solve(0 , nums , dp);
    }
};
