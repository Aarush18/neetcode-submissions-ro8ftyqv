class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";

        for (auto &str : strs) {
            for (auto &ch : str) {
                res.push_back(ch);
            }
            res.push_back((char)0xFFFFFFF);
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string cur = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == (char)0xFFFFFFF) {
                res.push_back(cur);
                cur = "";
            } else {
                cur.push_back(s[i]);
            }
        }

        return res;
    }
};
