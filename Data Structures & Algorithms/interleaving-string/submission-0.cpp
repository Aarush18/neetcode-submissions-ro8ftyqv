class Solution {
private:
    bool solve(int i , int j , int k , vector<vector<int>>& dp , string s1  , string s2 , string s3){
        if(i == s1.size() && j == s2.size() && k == s3.size()){
            return true;
        }
        if(k >= s3.size()){
            return false;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool result = false;

        if( i < s1.size() && s1[i] == s3[k]){
            result = solve(i + 1 , j , k + 1 , dp , s1 , s2 , s3);
        }
        if(result == false && s2[j] == s3[k]){
            result = solve(i , j + 1 , k + 1 , dp , s1 , s2 , s3);
        }

        return dp[i][j] = result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();

        if(n + m != o) return false;
        vector<vector<int>>dp(s1.size() + 1 , vector<int>(s2.size()  + 1 , - 1));
        return solve(0 , 0 , 0 , dp , s1 , s2 , s3);
    }
};
