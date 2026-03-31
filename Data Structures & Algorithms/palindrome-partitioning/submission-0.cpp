class Solution {
private:
    bool isPalindrome(string s){
        int i = 0 ;
        int j = s.size() - 1;

        while( i <= j ){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int ind , vector<string>& output , vector<vector<string>>& ans , string s){
        if(ind == s.size()){
            ans.push_back(output);
            return ;
        }

        for(int i = ind ; i < s.size() ; i++){
            string sub = s.substr(ind, i - ind + 1);
            if(isPalindrome(sub)){
                output.push_back(sub);
                solve(i + 1 , output , ans , s);
                output.pop_back();
            }
        }

    }


public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>output;

        solve(0 , output , ans , s);

        return ans;
    }
};