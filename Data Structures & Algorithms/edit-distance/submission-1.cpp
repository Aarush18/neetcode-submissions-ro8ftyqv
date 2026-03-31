class Solution {
private:
    int solve(int i , int j , string s , string t , vector<vector<int>>& dp){
        if(j < 0){
            return i + 1;
        }
        if( i < 0) return j + 1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return solve(i - 1 , j - 1 , s , t , dp);
        }

        int del = solve(i - 1 , j , s , t , dp);
        int ins = solve(i , j - 1 , s , t , dp);
        int rep = solve(i - 1 , j - 1, s , t , dp);

        return dp[i][j] = 1 + min({del , ins , rep});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n , vector<int>(m + 1 ,-1));


        return solve(n - 1 , m - 1 , word1 , word2 , dp);

    }
};
