class Solution {
private:

    bool isPalindrome(string s){
        int i = 0 ;
        int j = s.size() - 1;

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind , string s , vector<vector<string>>& res , vector<string>& output){
        if(ind >= s.size()){
            res.push_back(output);
            return ;
        }

        for(int i = ind ; i < s.size() ; i++){
            string newString = s.substr(ind , i - ind + 1);
            if(isPalindrome(newString)){
                output.push_back(newString);
                solve(i + 1 , s , res , output);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>output;

        solve(0 , s , res ,output);

        return res;
    }
};
