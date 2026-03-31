class Solution {
private:
    void solve(vector<string>& res , string output , string digits , unordered_map<char, vector<string>>&mp , int ind){
        if(ind == digits.size()){
            res.push_back(output);
            return;
        }

        vector<string> map_value = mp[digits[ind]];

        for(int i = 0 ; i < map_value.size(); i++){
            output += map_value[i];
            solve(res , output , digits , mp , ind + 1);
            output.erase(output.size() - map_value[i].size());
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
            solve(res , output , digits , mp , 0);
        }
        return res;
    }
};
