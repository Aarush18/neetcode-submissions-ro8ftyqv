class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordMap(wordList.begin() , wordList.end());
        queue<string> q;

        if(wordMap.find(endWord) == wordMap.end()){
            return 0 ;
        }

        q.push(beginWord);

        int level = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i< size; i++ ){
                auto word = q.front(); q.pop();

                if(word == endWord){
                    return level ;
                }

                for(int i = 0 ; i < word.size() ; i++){
                    char original = word[i];
                    for(char ch = 'a' ; ch <= 'z' ; ch++){
                        word[i] = ch;
                        if(wordMap.find(word) != wordMap.end()){
                            q.push(word);
                            wordMap.erase(word);
                        }
                    }
                    word[i] = original ;
                }
            }
            level++;
        }
        return 0;
    }
};
