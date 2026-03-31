class Solution {
private:
    int solve(int ind , vector<int>& dp , string s){
        if(ind == s.size()){
            return 1;
        }

        if(s[ind] == '0'){
            return 0;
        }


        if(dp[ind] != -1){
            return dp[ind];
        }

        int ways = 0 ;

        ways += solve(ind + 1 , dp , s);

        if(ind + 1 < s.size()){
            auto two = (s[ind] - '0')* 10 + (s[ind + 1] - '0');
            if(two >= 10 && two <= 26){
                ways+= solve(ind + 2 , dp , s);
            }
        }

        return dp[ind] = ways;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1 , -1);

        return solve(0 , dp , s);
    }
};
