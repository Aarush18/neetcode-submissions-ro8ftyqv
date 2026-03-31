class Solution {
private:
    int solve(int ind , vector<int>& dp , vector<int>& nums , int end){
        if(ind > end){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int pick = nums[ind] + solve(ind + 2 , dp , nums , end);
        int notPick = solve(ind + 1 , dp , nums , end);

        return dp[ind] = max(pick , notPick);
    }
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int>dp1(n + 1 , -1);
        vector<int>dp2(n + 1 , -1);

        int rob1 = solve(0 , dp1 , nums , n - 2);
        int rob2 = solve(1 , dp2 , nums , n - 1);

        return max(rob1 , rob2);
    }
};
