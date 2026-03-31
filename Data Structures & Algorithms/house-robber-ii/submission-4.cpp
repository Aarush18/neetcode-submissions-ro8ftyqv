class Solution {
private:
    int solve(vector<int>& nums , vector<int>& dp , int ind , int n ){
        if(ind > n){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + solve(nums , dp , ind + 2 , n);
        int notPick = solve(nums , dp , ind + 1 , n);

        return dp[ind] = max(pick , notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1 (n + 1 , -1);
         vector<int> dp2 (n + 1 , -1);

        int t1 = solve(nums , dp1 , 0 , n-2);
        int t2 = solve(nums ,dp2, 1 , n-1);

        return max(t1 , t2);
    }
};