class Solution {
public:
    string longestPalindrome(string s) {

        int resLen = 0 ;

        string ans = "";

        for(int i = 0 ; i < s.size() ; i++){

            int l = i ;
            int r = i ;
            
            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
                if(r - l + 1 > resLen){
                    resLen = r - l + 1;
                    ans = s.substr(l , r - l + 1);
                }
                l--;
                r++;
            }

            l = i ;
            r = i + 1;

            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
                if(r - l + 1 > resLen){
                    resLen = r - l + 1;
                    ans = s.substr(l , r - l + 1);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};
