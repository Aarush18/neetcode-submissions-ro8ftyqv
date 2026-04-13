class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char , int> mp;

        for(int i = 0 ; i < 26 ; i++){
            mp[order[i]] = i;
        }

        for(int i = 0 ; i < words.size() - 1; i++){
            auto word1 = words[i];
            auto word2 = words[i + 1];

            if(word1.size() > word2.size() && word1.substr(0 , word2.size()) == word2){
                return false;
            }

            for(int j = 0 ; j < min(word1.size() , word2.size()); j++){
                if(word1[j] != word2[j]){
                    if(mp[word1[j]] > mp[word2[j]]){
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};