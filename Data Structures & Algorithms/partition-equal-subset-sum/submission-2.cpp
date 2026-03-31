class Solution {
private:
    bool solve(int ind , int target , vector<int>& nums ,  vector<vector<int>>& dp){
        if(ind == nums.size()){
            if(target == 0){
                return true;
            }
            return false;
        }

        if(target < 0){
            return false;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        bool take = solve(ind + 1 , target - nums[ind] , nums , dp);
        bool notTake = solve(ind + 1 , target  ,  nums , dp );

        return dp[ind][target] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {  

        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(sum%2 != 0){
            return false;
        }

        vector<vector<int>> dp(nums.size() +1 , vector<int>(sum/2 + 1, -1));

        return solve(0 , sum/2 , nums ,dp);
    }
};
