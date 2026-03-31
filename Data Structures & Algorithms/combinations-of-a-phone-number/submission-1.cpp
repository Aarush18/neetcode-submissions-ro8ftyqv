class Solution {
private:
    void solve(int ind , string digits , vector<string>& res , string output , unordered_map<char , vector<string>>& mp){

        if(ind == digits.size()){
            res.push_back(output);
            return ;
        }

        vector<string> mapVal = mp[digits[ind]];

        for(int i = 0 ; i < mapVal.size(); i++){
            output+= mapVal[i];
            solve(ind + 1 , digits , res , output , mp);
            output.erase(output.size() -  mapVal[i].size());
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> mp;

        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};

        vector<string> res;
        string output;

        if(!digits.empty()){
            solve(0 , digits , res , output , mp);
        }

        return res;
    }
};
