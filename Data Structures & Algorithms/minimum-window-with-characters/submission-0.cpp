class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        for(int i = 0 ; i < t.size() ; i++){
            hash[t[i]]++;
        }

        int m = t.size();

        int l = 0;
        int r = 0;
        int n = s.size();
        int cnt = 0;
        int sIND = -1;
        int minlen = 1e9;
        
        while( r < n ){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;

            while( cnt == m) {

                if(r - l + 1 < minlen){
                    minlen = r-l+1;
                    sIND = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return sIND == -1 ? "": s.substr(sIND , minlen);
        
    }
};
