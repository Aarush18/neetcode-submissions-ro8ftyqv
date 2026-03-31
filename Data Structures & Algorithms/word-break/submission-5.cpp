class Solution {
private:
    bool solve(int ind , string& s , vector<string>& wordDict , vector<int>& dp){
        if(ind == s.size()){
            return true;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        for(int i = ind ; i < s.size(); i++){
            string newString = s.substr(ind , i - ind + 1);
            if(find(wordDict.begin() , wordDict.end() , newString) != wordDict.end()){
                if(solve(i + 1 , s , wordDict , dp) == true){
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1 , -1);
        return solve(0 , s , wordDict , dp);
    }
};
