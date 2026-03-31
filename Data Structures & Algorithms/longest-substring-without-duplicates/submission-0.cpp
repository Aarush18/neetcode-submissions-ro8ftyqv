class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> mpp;

        int l = 0 ; int r = 0 ; 
        int n = s.size();

        int maxlen = 0;

        while(r < n){

            
            mpp[s[r]]++;

            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }
            int len = r - l + 1;
            maxlen = max(maxlen , len);
            
            r++;

        }
        return maxlen;
    }
};
