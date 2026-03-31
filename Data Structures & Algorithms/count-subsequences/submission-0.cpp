class Solution {
 
private:
    int solve( int i , int j , vector<vector<int>> &dp , string s , string t){
        if(j < 0) return 1;

        if(i < 0) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] = solve(i - 1 , j - 1 , dp , s , t) + solve(i - 1 , j , dp , s ,t);
        }else{
            return dp[i][j] = solve(i - 1 , j , dp ,s , t);
        }
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1 , -1));
        return solve(s.size() - 1 , t.size() - 1 , dp , s , t);
    }
};
