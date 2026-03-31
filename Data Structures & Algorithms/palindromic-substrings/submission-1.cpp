class Solution {
public:
    int countSubstrings(string s) {
         int cnt = 0;

        for(int i = 0 ; i < s.size(); i++){
            // odd length
            int l = i;
            int r = i;

            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
                
                cnt++;
                l = l - 1;
                r = r + 1;
            }

            l = i ;
            r = i + 1 ;

            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
                
                cnt++;
                l = l -1;
                r = r + 1;
            }
        }
        return cnt;
    }
};
