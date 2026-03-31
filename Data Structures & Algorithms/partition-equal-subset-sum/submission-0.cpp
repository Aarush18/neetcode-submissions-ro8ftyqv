class Solution {
private: 
    bool solve(int ind , int sum , vector<vector<int>>&dp , vector<int>& nums , int n ){

        if(ind == n) {
            if(sum == 0) {
                return true;
            }
            return false;
        }

        if(sum < 0) return false;

        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }

        bool take = solve(ind + 1 , sum - nums[ind] , dp , nums , n);

        bool notTake = solve(ind + 1 , sum , dp , nums , n);

        return dp[ind][sum] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ; 

        for(int i = 0 ; i < n ; i++){
            sum+= nums[i];
        }
        vector<vector<int>> dp(n , vector<int>(sum + 1 , -1));
        if(sum % 2 == 1) return false;

        return solve(0 , sum/2 , dp , nums , n);
    }
};
