class Solution {
private:
    int solve(int ind1 , int ind2 , vector<vector<int>>& dp , string text1 , string text2){
        if(ind1 < 0 || ind2 < 0){
            return 0 ;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1 + solve(ind1 - 1 , ind2 - 1 , dp , text1 , text2);
        }

        return dp[ind1][ind2] = max(
            solve(ind1-1 , ind2 , dp , text1 , text2) ,
            solve(ind1 , ind2 -1 , dp , text1 , text2)
        );
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n , vector<int>(m + 1, -1));
        

        return solve(n - 1 , m - 1 , dp , text1 , text2);
    }
};
