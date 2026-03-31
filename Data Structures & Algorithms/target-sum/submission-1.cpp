class Solution {
private:
    int solve(int ind , int sum , int target , vector<int>& nums , vector<vector<int>>& dp , int OFFSET){

        if(ind == nums.size()){
            if(sum == target){
                 return 1;
            }
            return 0;
        }
        
        if(dp[ind][sum + OFFSET] != -1){
            return dp[ind][sum + OFFSET];
        }

        int add = solve(ind + 1 , sum + nums[ind] ,  target , nums , dp , OFFSET);
        int subt = solve(ind + 1 , sum - nums[ind] , target , nums , dp , OFFSET);

        return dp[ind][sum + OFFSET] = add + subt;

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalsum = accumulate(nums.begin() , nums.end() , 0);

        vector<vector<int>> dp(nums.size() , vector<int>(2 * totalsum + 1 , -1));
        return solve( 0 , 0 , target , nums , dp , totalsum);
    }
};
