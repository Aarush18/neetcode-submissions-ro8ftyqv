class Solution {
private:
    int solve(int ind , string s , vector<int>& dp , int n ){
        if(ind == n){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        if(s[ind] == '0'){
            return 0;
        }

        int ways = 0 ;

        ways += solve(ind + 1 , s , dp , n);

        if(ind + 1 < n){
            int two = (s[ind] - '0') * 10 + (s[ind+1] - '0');
            if(two >= 10 && two <= 26){
                ways+= solve( ind + 2 , s , dp , n);
            }
        }

        return dp[ind] = ways;

    }
public:
    int numDecodings(string s) {
        vector<int> dp (s.size() , -1);
        return solve(0 , s , dp , s.size());
    }
};
