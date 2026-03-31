class Solution {
private:
    void solve(int open , int close , vector<string>& ans , int n , string curr){

        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }
        
        if(open < n){
            solve(open + 1 , close , ans , n , curr + "(" );
        }
        if(close < open){
            solve(open , close + 1 , ans , n , curr + ")");
        }

    }
public:
    vector<string> generateParenthesis(int n) { 

        vector<string> ans;

        solve(0 , 0 , ans , n , "");

        return ans;
    }
};
