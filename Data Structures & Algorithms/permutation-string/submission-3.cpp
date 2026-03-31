class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash[26] = {0};

        for(int i = 0 ; i < s1.size() ; i++){
            hash[s1[i] - 'a']++; 
        }

        int l = 0;
        int r = 0;
        int n = s2.size();

        while( r < n){
            if(hash[s2[r] - 'a'] > 0){

                int tmp[26];
                for(int k = 0; k < 26; k++) tmp[k] = hash[k];

                l = r;
                while( (l - r) < s1.size() && l < n){
                    if(tmp[s2[l] - 'a'] == 0){
                        break;
                    }
                    tmp[s2[l] - 'a']--;
                    l++; 
                }
                if( (l - r) == s1.size() ){
                    return true;
                }
            }
            r++;
        }
        return false;
    }
};
