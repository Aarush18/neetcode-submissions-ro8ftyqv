class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0 ;

        for(int i = 0 ; i < s.size(); i++){
            // odd length
            int l = i;
            int r = i;

            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
                if(r - l + 1 > resLen){
                    res = s.substr(l , r - l + 1);
                    resLen = r - l + 1;
                }
                l = l - 1;
                r = r + 1;
            }

            l = i ;
            r = i + 1 ;

            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
                if(r - l + 1 > resLen){
                    res = s.substr(l , r - l + 1);
                    resLen = r - l + 1;
                }
                l = l -1;
                r = r + 1;
            }
        }
        return res;
    }
};
