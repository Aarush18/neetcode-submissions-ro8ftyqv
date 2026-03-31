class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> freq_s1(26 , 0);
        vector<int> freq_s2(26 , 0);

        for(int i = 0 ; i < s1.size() ; i++){
            freq_s1[s1[i] - 'a']++;
        }

        int i = 0;
        int j = 0;

        while ( j < m ){
            freq_s2[s2[j] - 'a']++;

            if( j - i + 1 > n){
                freq_s2[s2[i] - 'a']--;
                i++;
            }

            if(freq_s1 == freq_s2){
                return true;
            }
            j++;
        }
        return false;
    }
};
