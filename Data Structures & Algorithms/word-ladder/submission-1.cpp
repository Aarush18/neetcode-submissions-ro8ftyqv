class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        unordered_set<string > mp(wordList.begin() , wordList.end());

        if(mp.find(endWord) == mp.end()){
            return 0 ;
        }

        int level = 1;

        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++){
                auto word = q.front();
                q.pop();

                if(word == endWord){
                    return level;
                }

                for(int i = 0 ; i < word.size() ; i++){
                    char original = word[i];
                    for(char ch = 'a' ; ch <= 'z' ; ch++){
                        word[i] = ch ;
                        if(mp.find(word) != mp.end()){
                            q.push(word);
                            mp.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level ++;
        }
        return 0 ;
    }
};
