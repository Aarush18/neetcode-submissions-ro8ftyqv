class Solution {
private:
    void solve(int ind , string& s , vector<string>& res , string& currString , vector<string>& wordDict){
        if(ind == s.size()){
            currString.pop_back();
            res.push_back(currString);
            currString+=" ";
            return;
        }


        for(int i = ind ; i < s.size() ; i++){
            string substr = s.substr(ind , i - ind + 1);
            if(find(wordDict.begin() , wordDict.end() , substr) != wordDict.end()){
                currString+= substr;
                currString+= " ";

                solve(i + 1 , s , res , currString , wordDict);

                currString.pop_back();
                currString.erase(currString.size() - substr.size() , substr.size());
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string currString = "";

        solve(0 , s , res , currString , wordDict);

        return res;
    }
};