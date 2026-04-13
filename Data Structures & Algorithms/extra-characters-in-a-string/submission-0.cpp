class Solution {
private:
    int solve(int ind , string s , vector<string>& dict , vector<int>& dp){
        int ans = 0 ;

        if(ind == s.size()){
            return 0 ;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        ans = 1 + solve(ind + 1 ,s , dict , dp);

        for(int i = ind ; i < s.size(); i++){
            string substr = s.substr(ind , i - ind + 1);
            if(find(dict.begin() , dict.end() , substr) != dict.end()){
                ans = min(ans , solve(i + 1 , s , dict , dp));
            }
        }

        return dp[ind] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size() , -1);
        return solve(0 , s , dictionary , dp);
    }
};