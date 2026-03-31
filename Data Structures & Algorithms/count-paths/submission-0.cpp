class Solution {
private:
    int solve(int i , int j , vector<vector<int>>& dp , int n , int m){
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(i >= m || j >= n || i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        return dp[i][j] = solve(i + 1 , j , dp , n , m) + solve(i , j + 1 , dp , n , m);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return solve(0 , 0 , dp , m , n);
    }
};
